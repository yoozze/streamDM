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

	BasicClassificationEvaluator eval;
	eval.setParams("{\"Frequency\":\"5000\"}");
	learner.setEvaluator(&eval);

	int counter = 0;
	bool testing = false;
	Instance* inst;
	int setSize = 100000; // max: 581012
	const double trainingSetFraction = 0.8;

	std::cout << "Training... ";

	while (reader.hasNextInstance()) {
		counter++;

		if (counter % 1000 == 0) {
			printf("%.2f%% ", (double)counter / setSize * 100);
		}

		if (counter > setSize) {
			break;
		}

		inst = reader.nextInstance();

		if (counter <= trainingSetFraction * setSize) {
			//learner.process(*inst);
			learner.train(*inst);
		} else {
			learner.getEvaluator()->addResult(*inst, learner.getPrediction(*inst));

			if (!testing) {
				std::cout << endl << "Testing... ";
				testing = true;
			}
		}

		delete inst;
	}

	// Output evaluation
	std::cout << endl << eval.toString() << endl;

	// Output model
	string modelFile = "hoeffdingTree.json";

	if (!learner.exportToFile(modelFile)) {
		printf("Failed to export model to file: %s .", modelFile.c_str());
		return 1;
	} else {
		printf("Model written to: %s\n", modelFile.c_str());
	}

	return 0;
}
