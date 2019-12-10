#include "Majorityclass.h"
#include "../../../Common.h"

REGISTER_CLASS(MajorityClass);
REGISTER_COMMAND_LINE_PARAMETER(MajorityClass, "{\"type\":\"Learner\","
		"\"name\":\"MajorityClass\","
		"\"parameter\":{"
		"}}"
		"");

MajorityClass::MajorityClass() {
	instancesSeen = 0;
	init = false;
	predArray = nullptr;
	classCounts = nullptr;
	predClassCount = 0;
}

MajorityClass::~MajorityClass() {
	if (init) {
		delete[] classCounts;
	}
	if (predArray != nullptr) {
		delete[] predArray;
	}
}

void MajorityClass::doSetParams() {
	//
}

void MajorityClass::train(const Instance& instance) {
	if (init == false) {
		init = true;
		classCounts = new int[instance.getNumberClasses()];
		for (int i = 0; i < instance.getNumberClasses(); i++) {
			classCounts[i] = 0;
		}
	}
	
	int label = instance.getLabel();
	classCounts[label]++;
}

double* MajorityClass::getPrediction(const Instance& instance) {
    if (predArray == nullptr) {
        predClassCount = instance.getNumberClasses();
        predArray = new double[predClassCount];
    }

	for (int i = 1; i < predClassCount; i++) {
		predArray[i] = 0.0;
	}

    if (!init) {
        return predArray;
    }
    
    int pred = 0;
	double max = classCounts[0];
	for (int i = 1; i < predClassCount; i++) {
		if (max < classCounts[i]) {
			max = classCounts[i];
			pred = i;
		}
	}

	predArray[pred] = 1.0;
	return predArray;
}
