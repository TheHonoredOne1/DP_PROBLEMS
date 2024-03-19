#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int getMaxPathSum(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        dp[n - 1][i] = grid[n - 1][i];
    }
    for (int i = (n - 2); i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + grid[i][j];
            }
            else if (j == (m - 1))
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1]) + grid[i][j];
            }
            else
            {
                dp[i][j] = grid[i][j] + max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1]));
            }
        }
    }
    int ans = -1e9;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[0][i]);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << getMaxPathSum(grid, n, m) << endl;
    return 0;
}
/*
3 3
10 2 3
3 7 2
8 1 5
=> 25

4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
=> 105

4 6
10 10 2 -13 20 4
1 -9 -81 30 2 5
0 10 4 -79 2 -10
1 -5 2 20 -11 4
=> 74
*/
