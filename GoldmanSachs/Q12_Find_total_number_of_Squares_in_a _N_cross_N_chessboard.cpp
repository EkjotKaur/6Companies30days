// Find total number of Squares in a N*N chessboard

#include <bits/stdc++.h>
using namespace std;
#define ifo                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int solve(int n)
{
    if (n < 2)
        return n;
    vector<int> A(n+1);
    for (int i = 1; i <= n; i++)
        A[i] = A[i - 1] + i * i;
    return A[n];
}

int main()
{
    ifo;
    int n;
    cin >> n;
    cout<<solve(n)<<"\n";
}
