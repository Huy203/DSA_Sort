#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<math.h>
#include<iostream>

using namespace std;

struct Book {
    string id, title, price, user_id, profileName, helpfulness, score, time, summary, text;
};

struct AVL {
    vector<Book> book;
    AVL* left;
    AVL* right;
};






