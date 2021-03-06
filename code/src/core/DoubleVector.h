/*
 * Copyright (C) 2015 Holmes Team at HUAWEI Noah's Ark Lab.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef DOUBLEVECTOR_H_
#define DOUBLEVECTOR_H_

#include <vector>
#include "../utils/json.h"
#include "../API.h"

using namespace std;

class STREAMDM_API DoubleVector
{
public:
	DoubleVector();
	virtual ~DoubleVector();

public:
    void addToValue(int index, double val);
    void setValue(int index, double val);
    double getValue(int index);
    int numValues();
    double sumOfValues();

    bool exportToJson(Json::Value& jv);
    bool importFromJson(const Json::Value& jv);

protected:
    vector<double> m_dataVec;
};

#endif /* DOUBLEVECTOR_H_ */
