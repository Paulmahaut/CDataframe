#ifndef CDATAFRAME_H  //Prevent from multiple treatment
#define CDATAFRAME_H

#include "column.h" 

typedef struct {
    COLUMN** columns;  // Array of pointers to columns
    int num_columns;   
    int capacity;      
} CDataframe;


CDataframe* create_cdataframe();
void print_cdataframe(CDataframe* df) 


#endif // CDATAFRAME_H
