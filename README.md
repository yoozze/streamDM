# streamDM-C++: C++ Stream Data Mining 

streamDM in C++ implements extremely fast streaming decision trees in C++ for big data streams. It is a project developed at Huawei Noah's Ark Lab. streamDM in C++ is licensed under Apache Software License v2.0.

The main advantages of streamDM in C++ over other C/C++ data stream libraries are the following:

- Faster than VFML in C and MOA in Java.
- Evaluation and learners are separated, not linked together.
- It contains several methods for learning numeric attributes.
- It is easy to extend and add new methods.
- The adaptive decision tree is more accurate and does not need an expert user to choose optimal parameters to use.  
- It contains powerful ensemble methods. 
- It is much faster and uses less memory.

## Getting Started

### Install with pip

TODO

### Build from source
Prerequisites:
* Python 3 (with `python-dev` on linux)
* numpy package
* pip package manager 

Clone git repository:
```
git clone https://github.com/klemenkenda/streamDM-Cpp.git
```

#### Linux

Install `gcc`, e.g. on Ubuntu:
```
sudo apt update
sudo apt install build-essential
```
Install [SWIG](http://www.swig.org/download.html). Many linux distributions include packages of SWIG, e.g. Ubuntu:
```
sudo apt install swig
```
Set environment variables, e.g.:
```
export PYTHON_INCLUDE="/usr/include/python3.6"
export NUMPY_INCLUDE="/home/username/.local/lib/python3.6/site-packages/numpy/core/include"
```
Build:
```
cd streamDM-Cpp
make
```
To test your build, first make sure `sklearn` is installed:
```
pip3 install sklearn
```
Run test script:
```
cd build/release
python3 test.py
```

#### Windows

Install [SWIG](http://www.swig.org/download.html) and add it to system path, e.g.:
```
setx path "%path%;c:\swigwin"
```
Set environment variables, e.g.:
```
setx NUMPY_INCLUDE "C:\Users\username\Anaconda3\Lib\site-packages\numpy\core\include"
setx PYTHON_INCLUDE "C:\Users\username\Anaconda3\include"
setx PYTHON_LIB "C:\Users\username\Anaconda3\libs\python37.lib"
```
Install Visual Studio (with C++ support).
Open solution and build it (with release configuration):
```
build/streamDM-cpp.sln
```
To test your build, first make sure `sklearn` is installed:
```
pip install sklearn
```
Run test script:
```
cd build/release
python test.py
```

## Methods

streamDM in C++ executes tasks. Tasks can be evaluation tasks as "EvaluatePrequential" or "EvaluateHoldOut" and the parameters needed are a learner, a stream reader, and an evaluator.

The methods currently implemented are: Naive Bayes, Logistic Regression, Perceptron, Majority Class, Hoeffding Tree, Hoeffding Adaptive Tree, and Bagging.

The stream readers currently implemented support Arff, C45, and LibSVM formats.



