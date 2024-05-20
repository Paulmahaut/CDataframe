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


void hard_fill(CDataframe * df);



/**
 * @brief Delete a whole row from the Dataframe at position index
 * @param df pointer to CDataframe
 * @param index integer
 * @return integer either 0 or 1 to know if the function was successful
 *
 */

int delete_row_CD(CDataframe* df, int index);

/**
 * @brief Delete a whole column from the Dataframe by freeing it's pointer at position index
 * @param df pointer to CDataframe
 * @param col_index integer
 * @return either 0 or 1 to know if the function was successful
 */
int delete_column_CD(CDataframe* df, int col_index);

void print_cdataframe(CDataframe* df);

void print_column_by_index(CDataframe* df, int index);

void display_the_numbers_of_cells_equal_to_x(CDataframe* df, int x);

void display_the_numbers_of_cells_greater_than_x(CDataframe* df, int x);

void display_the_numbers_of_cells_less_than_x(CDataframe* df, int x);

void display_part_of_the_Cdataframe_rows(CDataframe* df, int start, int end);


void display_part_of_the_Cdataframe_columns(CDataframe* df, int start, int end);

void display_column_names(CDataframe* df);

/**
 * Find if the value x given exists in the dataframe
 * @param1 Pointer to Cdataframe
 * @param2 Value x to find
 * @return 1 if the value exists in all the dataframe and 0 otherwise
 */

int existence_of_x(CDataframe*, int);

int replace_value_CD(CDataframe*, int row , int col, int x);

#endif // CDATAFRAME_H
