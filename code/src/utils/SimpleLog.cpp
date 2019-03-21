
#include "SimpleLog.h"

SimpleLog::SimpleLog() {}
SimpleLog::~SimpleLog() {}


void SimpleLog::debug(const char* stringFormat, ...) throw() {
	va_list args;

	printf("[DEBUG] ");
	va_start(args, stringFormat);
	vfprintf(stdout, stringFormat, args);
	va_end(args);
	printf("\n");
}

void SimpleLog::debug(const std::string& message) throw() {
	cout << "[DEBUG] " << message << endl;
}

void SimpleLog::info(const char* stringFormat, ...) throw() {
	va_list args;

	printf("[INFO] ");
	va_start(args, stringFormat);
	vfprintf(stdout, stringFormat, args);
	va_end(args);
	printf("\n");
}

void SimpleLog::info(const std::string& message) throw() {
	cout << "[INFO] " << message << endl;
}

void SimpleLog::warn(const char* stringFormat, ...) throw() {
	va_list args;

	printf("[WARN] ");
	va_start(args, stringFormat);
	vfprintf(stdout, stringFormat, args);
	va_end(args);
	printf("\n");
}

void SimpleLog::warn(const std::string& message) throw() {
	cout << "[WARN] " << message << endl;
}

void SimpleLog::error(const char* stringFormat, ...) throw() {
	va_list args;

	printf("[ERROR] ");
	va_start(args, stringFormat);
	vfprintf(stderr, stringFormat, args);
	va_end(args);
	printf("\n");
}

void SimpleLog::error(const std::string& message) throw() {
	cout << "[ERROR] " << message << endl;
}
