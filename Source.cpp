#include"AVL.h"
int main()
{
    string fileInput = "Books_rating.csv";
    string fileOutput = "sorted_books_rating.csv";
    int size = pow(2, 15);
    externalSort(fileInput, fileOutput, size);
    return 0;
}
