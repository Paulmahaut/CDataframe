#include "cdataframe.c"
#include "column.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, value;
    char title[255];
    CDataframe* df = create_cdataframe(5);  

    if (df == NULL) {
        printf("Failed to create CDataframe. Out of memory.\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Column\n");
        printf("2. Insert Value into a Column\n");
        printf("3. Print Dataframe\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter column title: ");
                scanf("%254s", title);  
                COLUMN* col = create_column(title);
                if (col == NULL) {
                    printf("Failed to create column.\n");
                } else {
                    add_column(df, col);
                    printf("Column '%s' added.\n", title);
                }
                break;

            case 2:
                if (df->num_columns == 0) {
                    printf("No columns in dataframe. Add a column first.\n");
                    break;
                }
                printf("Enter column index (0 to %d): ", df->num_columns - 1);
                int col_index;
                scanf("%d", &col_index);
                if (col_index < 0 || col_index >= df->num_columns) {
                    printf("Invalid column index.\n");
                    break;
                }
                printf("Enter integer value to insert: ");
                scanf("%d", &value);
                if (!insert_value(df->columns[col_index], value)) {
                    printf("Failed to insert value.\n");
                } else {
                    printf("Value %d added to column '%s'.\n", value, df->columns[col_index]->title);
                }
                break;

            case 3:
                print_cdataframe(df);
                break;

            case 4:
                free_cdataframe(df);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
