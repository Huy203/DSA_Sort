#include"AVL.h"

int main()
{
    string fileInput = "Books_rating.csv";
    string fileOutput = "sorted_books_rating.csv";
    int size = pow(2, 15);
    int count = externalSort(fileInput, fileOutput, size);
    MergeFile(fileOutput, count);
    RemoveTempFile("temp/sorted", 92);
    return 0;
}
