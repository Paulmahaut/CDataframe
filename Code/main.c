#include "cdataframe.c"
#include "column.c"
#include <stdio.h>
#include <stdlib.h>
//Note le code peut boucler si on ne rentre pas un chiffre, je ne règle pas ce problème dans l'optique de faire la part 2

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Create an empty CDataframe\n");
    printf("2. Add a column to the CDataframe\n");
    printf("3. Fill your data frame (Hard fill or by Hand)\n");
    printf("4. Delete a column from the CDataframe\n");
    printf("5. Delete a row from the CDataframe\n");
    printf("6. Replace a value in the CDataframe\n");
    printf("7. Display the number of rows\n");
    printf("8. Display the number of columns\n");
    printf("9. Display the number of cells equal to x\n");
    printf("10. Display the number of cells greater than x\n");
    printf("11. Display the number of cells less than x\n");
    printf("12. Check existence of a value in the CDataframe\n");
    printf("13. Display a column by index\n");
    printf("14. Print the entire CDataframe\n");
    printf("15 Display a part of the CDatframe rows \n");
    printf("16 Display a part of the CDatframe columns \n");
    printf("0. Exit\n");
}

int main() {
    CDataframe* df = NULL;
    int choice, choice2 ,col_index, row_index, value, x,nb_rows, nb_cols;
    char titre[255];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter capacity for the CDataframe: ");
                scanf("%d", &value);
                df = create_cdataframe(value);
                if (df == NULL) {
                    printf("Failed to create CDataframe.\n");
                } else {
                    printf("CDataframe created successfully.\n");
                }
                break;
            case 2:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                }
                else {
                    printf("Name your new column : ");
                    scanf("%s",titre);
                    COLUMN* new_col = create_column(titre);
                    add_column(df, new_col);
                    printf("Column added to the CDataframe.\n");
                }
                break;
            case 3 :
                if (df == NULL)
                {
                    printf("CDataframe not created yet\n");

                }
                else
                {
                    printf("Choose 1 to Hard fill and 2 to fill by hand : ");
                    scanf("%d",&choice2);
                    switch (choice2){
                        case 1:
                        {
                            hard_fill(df);

                        }
                    break;
                        case 2:

                        printf("How many rows ?");
                        scanf("%d",&nb_rows);
                        int a;
                            printf("\nHow many columns ?");
                            scanf("%d", &nb_cols);
                            for (int i = 0; i< nb_cols; i++)
                            {
                                char *ti = NULL;
                                printf("Give the title of your column : ");
                                scanf("%s",ti);
                                add_column(df, create_column(ti));
                            }
                            for ( int i =0; i< nb_rows; i++)
                            {
                                printf("Insert a value to add");
                                scanf("%d", &value);
                                a=insert_value(df->columns[i], value);
                                if (!a)
                                {
                                    printf("Previous insertion failed...");
                                }
                            }
                    }
                    break;

                }
            case 4:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter index of column to delete: ");
                    scanf("%d", &col_index);
                    if (delete_column_CD(df, col_index)) {
                        printf("Column deleted from the CDataframe.\n");
                    } else {
                        printf("Failed to delete column.\n");
                    }
                }
                break;
            case 5:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter index of row to delete: ");
                    scanf("%d", &row_index);
                    if (delete_row_CD(df, row_index)) {
                        printf("Row deleted from the CDataframe.\n");
                    } else {
                        printf("Failed to delete row.\n");
                    }
                }
                break;
            case 6:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter row index: ");
                    scanf("%d", &row_index);
                    printf("Enter column index: ");
                    scanf("%d", &col_index);
                    printf("Enter new value: ");
                    scanf("%d", &value);
                    if (replace_value_CD(df, row_index, col_index, value)) {
                        printf("Value replaced in the CDataframe.\n");
                    } else {
                        printf("Failed to replace value.\n");
                    }
                }
                break;
            case 7:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    display_the_numbers_of_rows(df);
                }
                break;
            case 8:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    display_the_numbers_of_columns(df);
                }
                break;
            case 9:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter value x: ");
                    scanf("%d", &x);
                    display_the_numbers_of_cells_equal_to_x(df, x);
                }
                break;
            case 10:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter value x: ");
                    scanf("%d", &x);
                    display_the_numbers_of_cells_greater_than_x(df, x);
                }
                break;
            case 11:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter value x: ");
                    scanf("%d", &x);
                    display_the_numbers_of_cells_less_than_x(df, x);
                }
                break;
            case 12:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &x);
                    if (existence_of_x(df, x)) {
                        printf("Value exists in the CDataframe.\n");
                    } else {
                        printf("Value does not exist in the CDataframe.\n");
                    }
                }
                break;
            case 13:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter index of column to display: ");
                    scanf("%d", &col_index);
                    print_column_by_index(df, col_index);
                }
                break;
            case 14:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    print_cdataframe(df);
                }
                break;
            case 15:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter start index: ");
                    scanf("%d", &col_index);
                    printf("Enter end index: ");
                    scanf("%d", &row_index);
                    display_part_of_the_Cdataframe_rows(df, col_index, row_index);
                }
                break;
            case 16:
                if (df == NULL) {
                    printf("CDataframe not created yet.\n");
                } else {
                    printf("Enter start index: ");
                    scanf("%d", &col_index);
                    printf("Enter end index: ");
                    scanf("%d", &row_index);
                    display_part_of_the_Cdataframe_columns(df, col_index, row_index);
                }
                break;
            case 0:
                if (df != NULL) {
                    free_cdataframe(df);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}