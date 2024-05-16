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
void display_the_numbers_of_cells_equal_to_x(CDataframe* df, int x);
void display_the_numbers_of_cells_greater_than_x(CDataframe* df, int x);
void display_the_numbers_of_cells_less_than_x(CDataframe* df, int x);

#endif // CDATAFRAME_H
