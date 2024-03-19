#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

ll recursion(vector<vector<ll>> &grid, ll n, ll level, ll index)
{
    if (level == (n - 1))
    {
        return grid[n - 1][index];
    }
    ll ans1 = recursion(grid, n, level + 1, index);
    ll ans2 = recursion(grid, n, level + 1, index + 1);
    return min(ans2, ans1) + grid[level][index];
}



ll dynamic(vector<vector<ll>> &grid, ll n)
{
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        dp[n - 1][i] = grid[n - 1][i];
    }
    for (ll i = (n - 2); i >= 0; i--)
    {
        for (ll j = 0; j <= i; j++)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + grid[i][j];
        }
    }
    return dp[0][0];
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> grid(n);
    for (ll i = 0; i < n; i++)
    {
        grid[i] = vector<ll>(i + 1);
        for (ll j = 0; j <= i; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << recursion(grid, n, 0, 0) << endl;
    cout << dynamic(grid, n) << endl;
    return 0;
}
/*
4
1
2 3
4 5 6
7 8 9 10
=> 14

3
5
-1 3
22 1 -9
=> -1


4
2 
3 4
6 5 7
4 1 8 3
=> 14


1
-10 
=> 10
*/
