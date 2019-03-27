#include <iostream>
#include "Common.h"
#include "streams/ArffReader.h"
#include "learners/Classifiers/Trees/HoeffdingTree.h"
#include "evaluation/BasicClassificationEvaluator.h"

using namespace std;

//int main(int argc, char* argv[]) {
//	string taskName;
//	string taskParams;
//	bool ret = CommandLineParser::parser(argc, argv, taskName, taskParams);
//	if (!ret) {
//		return 0;
//	}
//
//	Task* task = (Task*)CREATE_CLASS(taskName);
//	task->setParams(taskParams);
//	task->doTask();
//
//	return 0;
//}

int main()
{
	// Prepare data
	string dataFile = "covtypeNorm.arff";
	ArffReader reader;

	if (!reader.setFile(dataFile)) {
		printf("Failed to open file: %s ", dataFile.c_str());
		return 1;
	}

	// Train
	HT::HoeffdingTree learner;

	//BasicClassificationEvaluator eval;
	//eval.setParams("{\"Frequency\":\"5000\"}");
	//learner.setEvaluator(&eval);

	int counter = 0;
	bool testing = false;
	Instance* inst;
	int setSize = 10000; // max: 581012
	const double trainingSetFraction = 0.8;

	// Build vectors
	std::cout << "Building vectors... " << endl;

	vector<vector<double>> X;
	vector<int> y;

	while (reader.hasNextInstance()) {
		counter++;

		if (counter > setSize) {
			break;
		}

		inst = reader.nextInstance();

		vector<double> x;

		for (int i = 0; i < inst->getNumberInputAttributes(); i++) {
			x.push_back(inst->getInputAttributeValue(i));
		}

		X.push_back(x);
		y.push_back(inst->getOutputAttributeValue(0));
	}

	std::cout << "Training... " << endl;

	learner.fit(X, y);

	//while (reader.hasNextInstance()) {
	//	counter++;

	//	if (counter % 1000 == 0) {
	//		printf("%.2f%% ", (double)counter / setSize * 100);
	//	}

	//	if (counter > setSize) {
	//		break;
	//	}

	//	inst = reader.nextInstance();

	//	if (counter <= trainingSetFraction * setSize) {
	//		//learner.process(*inst);
	//		learner.train(*inst);
	//	} else {
	//		learner.getEvaluator()->addResult(*inst, learner.getPrediction(*inst));

	//		if (!testing) {
	//			std::cout << endl << "Testing... ";
	//			testing = true;
	//		}
	//	}

	//	delete inst;
	//}

	// Output evaluation
	//std::cout << endl << eval.toString() << endl;

	// Predict
	std::cout << "Predicting... " << endl;

	for (int i = 0; i < 10; i++) {
		std::cout << "Predicted: " << learner.predict(X[i]) << ", Expected: " << y[i] << endl;
	}

	// Output model
	string modelFile = "hoeffdingTree.json";

	if (!learner.exportToFile(modelFile)) {
		printf("Failed to export model to file: %s .", modelFile.c_str());
		return 1;
	} else {
		printf("Model written to: %s\n", modelFile.c_str());
	}


	// Test
	/*vector<double> v = { 0.368684,0.141667,0.045455,0.184681,0.223514,0.071659,0.870079,0.913386,0.582677,0.875366,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 };
	vector<double> l = { 5 };
	DenseInstance instance;
	InstanceInformation ii;
	for (int i = 0; i < v.size(); i++)
	{
		ii.addAttribute(new Attribute(), i);
	}
	const vector<string> classes { "0", "1" };
	ii.addClass(new Attribute(classes), 0);
	instance.setInstanceInformation(&ii);
	instance.addValues(v);
	instance.addLabels(l);

	std::cout << instance.getLabel() << endl;
	std::cout << instance.getOutputAttributeValue(0) << endl;
	std::cout << instance.getInputAttributeValue(0) << endl;
	std::cout << endl;
	std::cout << instance.getNumberInputAttributes() << endl;
	std::cout << instance.getNumberOutputAttributes() << endl;
	std::cout << instance.getNumberClasses() << endl;
	std::cout << v.size() << endl;

	for (int i = 0; i < v.size() - 1; ++i)
		std::cout << instance.getInputAttributeValue(i) << ' ';*/

	return 0;
}
