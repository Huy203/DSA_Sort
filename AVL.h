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
    p->book.id = data.id;
    p->book.title = data.title;
    p->book.user_id = data.user_id;
    p->book.profileName = data.profileName;
    p->book.summary = data.summary;
    p->book.text = data.text;
    p->book.time = data.time;
    p->book.price = data.price;
    p->book.helpfulness = data.helpfulness;
    p->book.score = data.score;
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
    else if (data.id <= root->book.id)
    {
        byID(root->left, data);
    }
    else if (data.id > root->book.id)
    {
        byID(root->right, data);
    }
}

void insertAVL(AVL*& root, Book data)
{
    byID(root, data);
    balance(root);
}
AVL* readFileAVL(string info)
{
    ifstream fi(info); //read file
    AVL* root = NULL;
    Book book; //board card
    string temp;
    string line;
    getline(fi, line); // bo dong dau tien

    while (!fi.eof())
    {
        getline(fi, line);
        if (line == "")
        {
            break;
        }
        stringstream ss(line);// doc tung dong

        //read tung word truoc dau ;
        getline(ss, temp, ',');
        book.id = temp;

        getline(ss, temp, ',');//break ',' of title
        if (temp[0] == '"')
        {
            while (temp[temp.length() - 1] != '"')
            {
                book.title = temp + ',';
                getline(ss, temp, ',');
            };
            if (temp[temp.length() - 1] == '"')
                book.title = temp;
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
            while (temp[temp.length() - 1] != '"')
            {
                book.profileName = temp + ',';
                getline(ss, temp, ',');
            };
            if (temp[temp.length() - 1] == '"')
                book.profileName = temp;
        }
        else
            book.profileName = temp;

        getline(ss, temp, ',');
        book.helpfulness = temp;

        getline(ss, temp, ',');
        book.score = temp;

        getline(ss, temp, ',');
        book.time = temp;

        getline(ss, temp, ',');
        if (temp[0] == '"')
        {
            while (temp[temp.length() - 1] != '"')
            {
                book.summary = temp + ',';
                getline(ss, temp, ',');
            };
            if (temp[temp.length() - 1] == '"')
                book.summary = temp;
        }
        else
            book.summary = temp;

        getline(ss, temp, ',');
        if (temp[0] == '"')
        {
            while ((temp[temp.length() - 1] != '"') || (temp == ""))
            {
                book.text = temp + ',';
                getline(ss, temp, ',');
                if (temp == "")
                {
                    book.text = temp + ',';
                    getline(ss, temp, ',');
                }
            };
            if (temp[temp.length() - 1] == '"')
                book.text = temp;
        }
        else
            book.text = temp;
        //Insert
        insertAVL(root, book);
    }
    fi.close();
    return root;
}
void LNR(ofstream& fo, AVL* root)
{
    if (root == NULL)
        return;
    LNR(fo, root->left);
    fo << root->book.id << ","
        << root->book.title << ","
        << root->book.price << ","
        << root->book.user_id << ","
        << root->book.profileName << ","
        << root->book.helpfulness << ","
        << root->book.score << ","
        << root->book.time << ","
        << root->book.summary << ","
        << root->book.text << "," << endl << endl;
    LNR(fo, root->right);
}
void writeFile(string info, AVL* root)
{
    ofstream fo(info);
    if (root == NULL)
        return;
    LNR(fo, root);
    fo.close();
}
