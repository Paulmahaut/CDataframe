#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

typedef struct {
    COLUMN** columns;
    int num_columns;
    int capacity;
} CDataframe;

CDataframe* create_cdataframe(int capacity);
void add_column(CDataframe* df, COLUMN* col);
void print_cdataframe(CDataframe* df);
void print_column_by_index(CDataframe* df, int index); 

#endif // CDATAFRAME_H
