#include"AVL.h"


int main()
{
	string fileInput = "Books_rating.csv";
	string fileOutput = "sorted_books_rating.csv";
	AVL* root = readFileAVL(fileInput);
	writeFile(fileOutput, root);
	return 0;
}
