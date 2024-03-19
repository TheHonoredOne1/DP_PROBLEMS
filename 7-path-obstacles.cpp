#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll rec(ll n, ll m, vector<vector<ll>> &grid, ll ind1, ll ind2)
{
    if (ind1 < n && ind2 < m && grid[ind1][ind2] == 1)
    {
        return 0;
    }
    if (ind1 >= n || ind2 >= m)
    {
        return 0;
    }
    if (ind1 == (n - 1) && ind2 == (m - 1))
    {
        return 1;
    }
    ll sm1 = rec(n, m, grid, ind1 + 1, ind2);
    ll sm2 = rec(n, m, grid, ind1, ind2 + 1);
    return sm1 + sm2;
}
ll memo(ll n, ll m, vector<vector<ll>> &grid, ll ind1, ll ind2, vector<vector<ll>> &ans)
{
    if (ind1 < n && ind2 < m && grid[ind1][ind2] == 1)
    {
        return 0;
    }
    if (ind1 >= n || ind2 >= m)
    {
        return 0;
    }
    if (ind1 == (n - 1) && ind2 == (m - 1))
    {
        return 1;
    }
    if (ans[ind1][ind2] != -1)
    {
        return ans[ind1][ind2];
    }
    ll sm1 = memo(n, m, grid, ind1 + 1, ind2, ans);
    ll sm2 = memo(n, m, grid, ind1, ind2 + 1, ans);
    ans[ind1][ind2] = sm1 + sm2;
    return ans[ind1][ind2];
}
ll dynamic(vector<vector<ll>> &grid, ll n, ll m)
{
    vector<vector<ll>> dp(n, vector<ll>(m));
    if (grid[n - 1][m - 1] == 1)
    {
        return 0;
    }
    else
    {
        dp[n - 1][m - 1] = 1;
    }
    for (ll i = (m - 2); i >= 0; i--)
    {
        if (grid[n - 1][i] == 1)
        {
            dp[n - 1][i] = 0;
        }
        else
        {
            dp[n - 1][i] = dp[n - 1][i + 1];
        }
    }
    for (ll i = (n - 2); i >= 0; i--)
    {
        if (grid[i][m - 1] == 1)
        {
            dp[i][m - 1] = 0;
        }
        else
        {
            dp[i][m - 1] = dp[i + 1][m - 1];
        }
    }
    for (ll i = (n - 2); i >= 0; i--)
    {
        for (ll j = (m - 2); j >= 0; j--)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    return dp[0][0];
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    // 1-> obs // 0 -> clear path
    cout << rec(n, m, grid, 0, 0) << "\n";
    /////////////////////////////////////////////////////////////////
    vector<vector<ll>> ans(n, vector<ll>(m, -1));
    cout << memo(n, m, grid, 0, 0, ans) << "\n";
    /////////////////////////////////////////////////////////////////
    cout << dynamic(grid, n, m) << "\n";
    return 0;
}

/*
7 9
0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/
