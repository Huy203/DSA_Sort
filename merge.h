#pragma once
#include"AVL.h"
void merge(FirstNode arr[], int const left, int const mid, int const right)
{
    int n = mid - left + 1;
    int m = right - mid;

    FirstNode* L = new FirstNode[n], * R = new FirstNode[m];

    for (int i = 0; i < n; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < m; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n && j < m) {
        if (L[i].book.id.compare(R[j].book.id) <= 0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < m) {
        arr[k]
            = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
void mergeSort(FirstNode arr[], int const left, int const right)
{
    if (left >= right)
        return;

    auto mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void MergeFile(string fo, int count)
{
    ifstream* in = new ifstream[count];
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
    FirstNode* temp = new FirstNode[count];
    int number = 0;
    for (int i = 0; i < count; i++)
    {
        in[i] >> temp[i].book;
        temp[i].element = i;
    }
    do {
        mergeSort(temp, 0, count - 1);
        Book temporary;
        if (!in[temp[0].element].eof())
        {
            while (!in[temp[0].element].eof())
            {
                out << temp[0].book.id << ","
                    << temp[0].book.title << ","
                    << temp[0].book.price << ","
                    << temp[0].book.user_id << ","
                    << temp[0].book.profileName << ","
                    << temp[0].book.helpfulness << ","
                    << temp[0].book.score << ","
                    << temp[0].book.time << ","
                    << temp[0].book.summary << ","
                    << temp[0].book.text << endl;
                in[temp[0].element] >> temporary;
                if (temporary.id == temp[0].book.id)
                {
                    temp[0].book = temporary;
                    continue;
                }
                else
                {
                    if (temporary.id != "")
                        temp[0].book = temporary;
                    break;
                }
            }
            if (in[temp[0].element].eof() == true)
            {
                in[temp[0].element].close();
                for (int k = 0; k < count - 1; k++)
                {
                    temp[k] = temp[k + 1];
                }
                count--;
            }
        }
    } while (count != 0);
    out.close();
}
