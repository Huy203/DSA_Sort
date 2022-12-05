#include"AVL.h"
int main()
{
    string fileInput = "Books_rating.csv";
    string fileOutput = "sorted_books_rating.csv";
    int size = pow(2, 15);
     externalSort(fileInput, fileOutput, size);
     //sorted22.csv
    joinFile("temp/sorted", "sorted_books_rating.csv", 92, size);
    return 0;
}
