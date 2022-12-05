#include "header.h"

void LR(AVL*& root)
{
    AVL* p = root->right;
    root->right = p->left;
    p->left = root;
    root = p;
}
void RR(AVL*& root)
{
    AVL* p = root->left;
    root->left = p->right;
    p->right = root;
    root = p;
}
int height(AVL* root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
void balance(AVL*& root)
{
    if (root == NULL)
    {
        return;
    }
    int bal = height(root->left) - height(root->right);
    if (bal >= 2)//lech trai
    {
        if (height(root->left->left) >= height(root->left->right))//lech LL
        {
            RR(root);
        }
        else//lech LR
        {
            LR(root->left);
            RR(root);
        }
    }
    if (bal <= -2)//lech phai
    {
        if (height(root->right->right) >= height(root->right->left))//lech RR->xoay L
        {
            LR(root);
        }
        else //lech RL->xoay R->L
        {
            RR(root->right);
            LR(root);
        }
    }
}
AVL* createNodeAVL(Book data)
{
    AVL* p = new AVL;
    p->book.push_back(data);
    p->left = NULL;
    p->right = NULL;
    return p;
}
void byID(AVL*& root, Book data) // so sanh ID
{
    if (root == NULL)
    {
        root = createNodeAVL(data);
    }
    else if (data.id < root->book[0].id)
    {
        byID(root->left, data);
    }
    else if (data.id == root->book[0].id)
    {
        root->book.push_back(data);
    }
    else if (data.id > root->book[0].id)
    {
        byID(root->right, data);
    }
}
void insertAVL(AVL*& root, Book data)
{
    byID(root, data);
    balance(root);
}
void LNR(ofstream& fo, AVL* root)
{
    if (root == NULL)
    {
        return;
    }
    LNR(fo, root->left);
    for (auto x : root->book)
        fo << x.id << ","
        << x.title << ","
        << x.price << ","
        << x.user_id << ","
        << x.profileName << ","
        << x.helpfulness << ","
        << x.score << ","
        << x.time << ","
        << x.summary << ","
        << x.text << endl;
    LNR(fo, root->right);
    delete root;
}
void writeFile(string info, AVL* root)
{
    ofstream fo(info);
    if (fo.fail() == true)
    {
        cout << "Cant open file" << endl;
        exit(1);
    }
    if (root == NULL)
        return;
    LNR(fo, root);
    fo.close();
}
void joinFile(string input, string output, int num, int size)
{
    ofstream writedF;
    ifstream in;
    string line;
    Book book;
    string temp;
    writedF.open(output);
    if (writedF.fail())
    {
        cout << "Wr";
        return;
    }
    for (int i = 0; i < num; i++)
    {
        cout << i << endl;
        int a = pow(2, 10);
        string namefile = input + to_string(i) + ".csv";
        in.open(namefile);
        if (in.fail())
        {
            cout << "In" << i;
            return;
        }
        int j;
        for (j = 0; j < size; j++)
        {
            getline(in, line, '\n');
            if (line == "\n")
            {
                break;
            }
            else
            {
                writedF << line;
            }
        }

        in.close();
    }
}
void externalSort(string fi, string fo, int size)
{
    ifstream in;
    in.open(fi, ios::binary);
    string temp;
    string line;
    getline(in, line); // bo dong dau tien
    int count = 0,number=0;
    while (in)
    {
        //int number = 0;
        AVL* root = NULL;
        for (int i = 0; i < size; i++)
        {
            Book book;
            getline(in, line);
            if (line == "")
            {
                break;
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
                    while (temp == "")
                    {
                        book.profileName += temp + ',';
                        getline(ss, temp, ',');
                    }
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

            getline(ss, temp, ',');//break ',' of title
            if (temp[0] == '"')
            {
                book.text = "";
                while (temp[temp.length() - 1] != '"')
                {
                    book.text += temp + ',';
                    getline(ss, temp, ',');
                    while (temp == "")
                    {
                        book.text += temp + ',';
                        getline(ss, temp, ',');
                    }
                };
                if (temp[temp.length() - 1] == '"')
                    book.text += temp;
            }
            else
                book.text = temp;
            //Insert
            insertAVL(root, book);
            cout << number++ << endl;
        }
        writeFile("temp/sorted" + to_string(count) + ".csv", root);
        count++;
    }
    in.close();
}

