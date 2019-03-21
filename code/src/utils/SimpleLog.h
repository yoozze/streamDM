#ifndef SimpleLog_H_
#define SimpleLog_H_

#include <iostream>
#include <string>
//#include <stdio.h>
#include <stdarg.h>

using namespace std;

class SimpleLog {
public:
	SimpleLog();
	~SimpleLog();

	/**
	 * Log a message with debug priority.
	 * @param stringFormat Format specifier for the string to write
	 * in the log file.
	 * @param ... The arguments for stringFormat
	 **/
	void debug(const char* stringFormat, ...) throw();

	/**
	 * Log a message with debug priority.
	 * @param message string to write in the log file
	 **/
	void debug(const std::string& message) throw();

	/**
	 * Log a message with info priority.
	 * @param stringFormat Format specifier for the string to write
	 * in the log file.
	 * @param ... The arguments for stringFormat
	 **/
	void info(const char* stringFormat, ...) throw();

	/**
	 * Log a message with info priority.
	 * @param message string to write in the log file
	 **/
	void info(const std::string& message) throw();

	/**
	 * Log a message with warn priority.
	 * @param stringFormat Format specifier for the string to write
	 * in the log file.
	 * @param ... The arguments for stringFormat
	 **/
	void warn(const char* stringFormat, ...) throw();

	/**
	 * Log a message with warn priority.
	 * @param message string to write in the log file
	 **/
	void warn(const std::string& message) throw();

	/**
	 * Log a message with error priority.
	 * @param stringFormat Format specifier for the string to write
	 * in the log file.
	 * @param ... The arguments for stringFormat
	 **/
	void error(const char* stringFormat, ...) throw();

	/**
	 * Log a message with error priority.
	 * @param message string to write in the log file
	 **/
	void error(const std::string& message) throw();

};

#endif /* SimpleLog_H_ */
