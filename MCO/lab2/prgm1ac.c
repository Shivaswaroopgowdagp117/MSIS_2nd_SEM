#include <stdio.h>

int main(){

    int rows, cols, target;
    int mat[100][100];

    printf("Enter the number of rows and columns of the matrix: \n");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix: \n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Enter the target element to search: \n");
    scanf("%d", &target);

    int found = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(mat[i][j] == target)
            {
                found = 1;
                break;
            }       
        }
    }
     if (found == 1) {
        printf("Element %d found in the matrix.\n" , target);
    } else {
        printf("Element %d not found in the matrix.\n", target);
    }

    return 0;
}