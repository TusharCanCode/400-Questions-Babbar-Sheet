#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int N;
    cout<<"Enter the size of the array: ";
    cin>>N;
    int arr[N];
    cout<<"Enter the elements of the array:";
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    for(int i=0, j=0; j<N;)
    {
        if(i%2 == 0 && arr[i]>=0)
        {
            
        }
    }

    for(int i=0; i<N; i++)
        cout<<arr[i]<<' ';
}