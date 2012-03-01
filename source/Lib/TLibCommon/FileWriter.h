/* 
 * File:   FileWriter.h
 * Author: felsamps
 *
 * Created on February 29, 2012, 4:43 PM
 */

#ifndef _FILEWRITER_H
#define	_FILEWRITER_H

#include <cstdarg>
#include <cstdio>

#define NUM_FILES 1

#define PU_CHOICES_FILE 1

class FileWriter {

    static FILE *files[10];

public:

    FileWriter();
    static void init(int fn, std::string name);
    static void print(int fn, const char* str, ...);
    static void close(int fn);
    
};

#endif	/* _FILEWRITER_H */

