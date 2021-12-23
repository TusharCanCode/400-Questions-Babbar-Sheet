#include <vector>
#include <iostream>
using namespace std;

int minimumoperations(vector<int> arr, int N)
{
    int operations = 0;
    for (int i = 0, j = N - 1; i < j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
            continue;
        }

        else if (arr[i] > arr[j])
        {
            arr[j - 1] += arr[j];
            j--;
        }
        else
        {
            arr[i + 1] += arr[i];
            i++;
        }
        operations++;
    }
    return operations;
}

int main()
{
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;
    vector<int> array;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < a; i++)
    {
        int val;
        cin >> val;
        array.push_back(val);
    }

    cout << "Minimum number of merge operations required to make an array palindrome is equal to " << minimumoperations(array, a);
}