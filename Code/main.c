#include "cdataframe.c"
#include "column.c"
#include <stdio.h>
#include <stdlib.h>
//Note le code peut boucler si on ne rentre pas un chiffre, je ne règle pas ce problème dans l'optique de faire la part 2
int main() {
    int choice,choice2, value;
    int index;
    int mainChoice, subChoice, limit;
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
        printf("4. Other functionalities\n");
        printf("5. Exit\n");
       
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
                 

    while (1) {
        printf("\nMenu Principal:\n");
        printf("1. Displaying\n");
        printf("2. Usual Operations\n");
        printf("3. Analysis and Statistics\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1: // Displaying
                printf("\nDisplaying Options:\n");
                printf("1. Display a part of the CDataframe rows\n");
                printf("2. Display a part of the columns of the CDataframe DOESNT WORK\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter the number of rows to display: ");
                        scanf("%d", &limit);
                        printf("This functionality is not yet available.\n");
                        break;
                    case 2:
                        printf("Enter column index (0 to %d): ", df->num_columns - 1);
                        scanf("%d", &index);
                        print_column_by_index(df,index);
                        return 0;
                        break;
                    default:
                        printf("Invalid choice. Please choose again.\n");
                }
                break;
            case 2: // Usual operations
                printf("\nUsual Operations:\n");
                printf("1. Add a row of values\n");
                printf("2. Delete a row of values\n");
                printf("3. Add a column\n");
                printf("4. Delete a column\n");
                printf("5. Rename the title of a column\n");
                printf("6. Check the existence of a value\n");
                printf("7. Access/replace a cell value\n");
                printf("8. Display column names\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        printf("This functionality is not yet available.\n");
                        break;
                    default:
                        printf("Invalid choice. Please choose again.\n");
                }
                break;
            case 3: // Analysis and statistics
                printf("\nAnalysis and Statistics:\n");
                printf("1. Display the number of rows\n");
                printf("2. Display the number of columns\n");
                printf("3. Display the number of cells equal to a specific value\n");
                printf("4. Display the number of cells containing a value greater than a specific value\n");
                printf("5. Display the number of cells containing a value less than a specific value\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                         display_the_numbers_of_rows(df);
                         break;
                    case 2:
                            display_the_numbers_of_columns(df);
                            break; 
                    case 3:
                        
                    case 4:
                    case 5:
                        printf("This functionality is not yet available.\n");
                        break;
                    default:
                        printf("Invalid choice. Please choose again.\n");
                }
                break;
            case 4: // Exit
                continue; //ne fonctionne pas
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;

            case 5:
                free_cdataframe(df);
                printf("Exiting program.\n");
                return 0;

           
        }
    }
    return 0;
}

/*
int main() {
    CDataframe* df = create_cdataframe(5);  
    COLUMN* col = create_column("Test");
    add_column(df, col);
    insert_value(col, 123);
    insert_value(col, 456);

    print_column_by_index(df, 0);  // Doit imprimer les valeurs 123 et 456 pour la colonne "Test"

    free_cdataframe(df);
    return 0;
}
*/