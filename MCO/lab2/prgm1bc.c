#include <stdio.h>

int search(int mat[][100], int rows, int cols, int key)
{
     for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(mat[i][j] == key)
            {
                return 1; // element found
            } 
        }
    }
    return 0; // element not found
}

int main(){

    int rows, cols, key;
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
    scanf("%d", &key);

    if(search(mat, rows, cols, key))
    {
        printf("Element %d is present in the matrix. \n", key);
    }else{
        printf("Element %d is not present in the matrix. \n", key);
    }
}