//
// Created by abdel on 29/03/2024.
//

#ifndef UNTITLED1_COLUMN_H
#define UNTITLED1_COLUMN_H

#endif //UNTITLED1_COLUMN_H


typedef struct
{
    char title[255];
    int LS;
    int PS;
    int data[256];
}COLUMN;

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char *title);


