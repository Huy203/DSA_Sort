#include"AVL.h"
int main()
{
    string fileInput = "/Users/henry/Downloads/Books_rating.csv";
    string fileOutput = "/Users/henry/Downloads/sorted_books_rating.csv";
    int size = pow(2, 15);
    externalSort(fileInput, fileOutput, size);
    return 0;
}
