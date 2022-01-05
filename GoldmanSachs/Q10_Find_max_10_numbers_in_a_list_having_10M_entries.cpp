// Find max 10 numbers in a list having 10M entries

#include <bits/stdc++.h>
using namespace std;
#define ifo                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

void solve(int n, vector<int> &A)
{
    for (int i = n - 1; i >= n - 10; i--)
    {
        for (int j = n - 1; j >= n - i; j--)
        {
            if (A[j - 1] < A[j])
                swap(A[j - 1], A[j]);
        }
    }
}

int main()
{
    ifo;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    solve(n, A);

    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
}
