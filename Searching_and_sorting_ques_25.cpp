#include <bits/stdc++.h>
using namespace std;

int sum(int A[], int N)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += A[i];
    }
    return ans;
}

bool utility(int A[], int N, int M, int mid)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum > mid)
        {
            M--;
            i--;
            sum = 0;
        }
        if (M == 0)
            return false;
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;
    int start = *max_element(A, A + N);
    int end = sum(A, N);

    int res = start;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (utility(A, N, M, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

int main()
{
    int N, M;
    cout << "Enter the number of books: ";
    cin >> N;
    cout << "Enter the pages of each book: ";
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << "Enter the number of students: ";
    cin >> M;
    cout << "The maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value: " << findPages(A, N, M);
}