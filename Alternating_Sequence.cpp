#include <iostream>

using namespace std;

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void alternator(int *arr, int size)
{
    int index_1 = 0, index_2 = 0;
    while (index_1 < size && index_2 < size)
    {
        if (index_1 % 2 == 0 && arr[index_1] < 0)
        {
            index_1++;
            continue;
        }
        else if (index_1 % 2 && arr[index_1] > 0)
        {
            index_1++;
            continue;
        }
        index_2++;
        if (index_1 != index_2 && index_1 < index_2)
        {
            if (index_1 % 2 && arr[index_2] > 0)
            {
                swap(arr[index_1], arr[index_2]);
            }
            else if (index_1 % 2 == 0 && arr[index_2] < 0)
            {
                swap(arr[index_1], arr[index_2]);
            }
        }
        else
        {
            index_2++;
        }
    }
}

int main(void)
{
    int arr[] = {-1, 2, -6, 2, -3, 5};
    int size = sizeof(arr) / sizeof(int);
    alternator(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}