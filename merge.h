#pragma once
#include"AVL.h"
void merge(FirstNode arr[], int l, int r)
{
    int k;
    int m = l + (r - 1) / 2;
    int n1 = m - l + 1;
    int n2 = r - m;

    FirstNode L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].book.id <= R[j].book.id) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeFile(string fo, int count)
{
    ifstream in[count];
    for (int i = 0; i < count; i++)
    {
        in[i].open("temp/sorted" + to_string(i) + ".csv");
        if (in[i].fail())
        {
            cout << "Cant open file" << endl;
            exit(1);
        }
    }
    ofstream out(fo);
    out << "Id,Title,Price,User_id,profileName,review/helpfulness,review/score,review/time,review/summary,review/text" << endl;
    FirstNode temp[count];
    int number = 0;
    for (int i = 0; i < count; i++)
    {
        in[i] >> temp[i].book;
        temp[i].element = i;
    }
    do {
        merge(temp, 0, count - 1);
        for (int i = 0; i < count; i++)
        {
            Book temporary;
            if (!in[temp[i].element].eof())
            {
                while (!in[temp[i].element].eof())
                {
                    if (i == 0)
                    {
                        cout << number++ << endl;
                        out << temp[i].book;
                        in[temp[i].element] >> temporary;
                        if (temporary.id == temp[i].book.id)
                        {
                            //vtBook[i].push_back(temporary);
                            temp[i].book = temporary;
                            continue;
                        }
                        else
                        {
                            temp[i].book = temporary;
                            break;
                        }
                    }
                    break;
                }
                if (in[temp[i].element].eof() == true)
                {
                    for (int k = i; k < count - 1; k++)
                    {
                        temp[k] = temp[k + 1];
                    }
                    in[temp[i].element].close();
                    count--;
                }
            }
        }
    } while (count != 0);
    out.close();
}

