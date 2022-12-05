#include"merge.h"
int main()
{
    string fileInput = "Books_rating.csv";
    string fileOutput = "sorted_books_rating.csv";
    int size = pow(2, 15);
    int count = externalSort(fileInput, fileOutput, size);
    mergeFile(fileOutput, count);
    return 0;
}
