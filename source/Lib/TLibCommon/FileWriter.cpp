/* 
 * File:   FileWriter.cpp
 * Author: felsamps
 * 
 * Created on February 29, 2012, 4:43 PM
 */

#include <string>

#include "../TLibCommon/FileWriter.h"


FILE* FileWriter::files[10];

FileWriter::FileWriter() {
}

void FileWriter::init(int fn, std::string name) {
	files[fn] = fopen(name.c_str(), "w");
}

void FileWriter::print(int fn, const char* str, ...) {
	va_list args;
	char buffer[BUFSIZ];
	va_start(args, str);
	vsprintf(buffer, str, args);
	fprintf(files[fn], "%s", buffer);
	va_end(args);
}

void FileWriter::close(int fn) {
	fclose(files[fn]);
}
