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
struct FirstNode
{
    Book book;
    int element;
};
ifstream& operator>>(ifstream& in, Book& book)
{
    string temp, line;
    getline(in, line);

    if (line == "")
    {
        return in;
    }
    stringstream ss(line);// doc tung dong
    getline(ss, temp, ',');
    book.id = temp;

    getline(ss, temp, ',');//break ',' of title
    if (temp[0] == '"')
    {
        book.title = "";
        while (temp[temp.length() - 1] != '"')
        {
            book.title += temp + ',';
            getline(ss, temp, ',');
        };
        if (temp[temp.length() - 1] == '"')
            book.title += temp;
    }
    else
        book.title = temp;

    getline(ss, temp, ',');
    book.price = temp;

    getline(ss, temp, ',');
    book.user_id = temp;

    getline(ss, temp, ',');//break ',' of title
    if (temp[0] == '"')
    {
        book.profileName = "";
        while (temp[temp.length() - 1] != '"')
        {
            book.profileName += temp + ',';
            getline(ss, temp, ',');
        };
        if (temp[temp.length() - 1] == '"')
            book.profileName += temp;
    }
    else
        book.profileName = temp;

    getline(ss, temp, ',');
    book.helpfulness = temp;

    getline(ss, temp, ',');
    book.score = temp;

    getline(ss, temp, ',');
    book.time = temp;

    getline(ss, temp, ',');//break ',' of title
    if (temp[0] == '"')
    {
        book.summary = "";
        while (temp[temp.length() - 1] != '"')
        {
            book.summary += temp + ',';
            getline(ss, temp, ',');
            while (temp == "")
            {
                book.summary += temp + ',';
                getline(ss, temp, ',');
            }
        };
        if (temp[temp.length() - 1] == '"')
            book.summary += temp;
    }
    else
        book.summary = temp;

    getline(ss, temp);//break ',' of title
    book.text = temp;
    return in;
}



