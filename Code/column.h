//
// Created by abdel .
//

#ifndef UNTITLED1_COLUMN_H
#define UNTITLED1_COLUMN_H




typedef struct
{
    char title[255];
    int LS;
    int PS;
    int *data;
}COLUMN;

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char *title);

/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN *col, int value);

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN **col);

/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN *col);

/**
 * @brief Find the number of occurences of a value x
 * @param1 Pointer to a column
 * @param2 Integer to find x
 * @return Number of occurences of x
 */
int occurence_x(COLUMN*, int);



/***
 *Return the value at position x if given a valid index
 * @param1 Pointer to a column
 * @param2 Index to find the value
 * @return Integer value x
 */
int return_value (COLUMN*,int);



/***
 *Return the number of values greater than x
 * @param1 Pointer to a column
 * @param2 Integer to do the comparison
 * @return Number of occurrences
 */
int occurences_greater_x (COLUMN*,int);

/***
 *Return the number of values lower than x
 * @param1 Pointer to a column
 * @param2 Integer to do the comparison
 * @return Number of occurrences
 */
int occurences_lower_x (COLUMN*,int);



/***
 * Return a list of the indexes of the values equal to x
 * @param Pointer to column
 * @param integer x to do the comparison
 * @return Array of indexes
 */
int* index_equal_x(COLUMN * col, int x);



/***
 *Return a list of the index of the values greater than x
 * @param1 Pointer to a column
 * @param2 Integer to do the comparison
 * @return Array of indexes
 */
int* index_greater_x (COLUMN*,int);

/***
*@brief Return a list of the index of the values lower than x
 * @param1 Pointer to a column
 * @param2 Integer to do the comparison
 * @return Array of indexes
***/
int* index_lower_x (COLUMN*,int);




#endif //UNTITLED1_COLUMN_H