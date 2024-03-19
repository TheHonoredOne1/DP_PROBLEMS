#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll recursion(ll day, vector<vector<ll>> &points, ll last, ll numdays)
{
    if (day >= numdays)
    {
        return 0;
    }
    ll max_points = 0;
    for (ll i = 0; i < 3; i++)
    {
        if (i != last)
        {
            max_points = max(max_points, points[day][i] + recursion(day + 1, points, i, numdays));
        }
    }
    return max_points;
}

ll dynamic(vector<vector<ll>> &points, ll days)
{
    vector<vector<ll>> dp(days, vector<ll>(3));
    dp[days - 1] = points[days - 1];
    for (ll day = days - 2; day >= 0; day--)
    {
        dp[day][0] = points[day][0] + max(dp[day + 1][1], dp[day + 1][2]);
        dp[day][1] = points[day][1] + max(dp[day + 1][0], dp[day + 1][2]);
        dp[day][2] = points[day][2] + max(dp[day + 1][0], dp[day + 1][1]);
    }
    ll ans = max(dp[0][0], max(dp[0][1], dp[0][2]));
    return ans;
}
int main()
{
    ll days;
    cin >> days;
    vector<vector<ll>> points(days, vector<ll>(3));
    for (ll i = 0; i < days; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << recursion(0, points, -1, days) << endl;
    cout << dynamic(points, days) << endl;
    return 0;
}
/*
test cases 

3
1 2 5 
3 1 1
3 3 3
=> 3


3
10 40 70
20 50 80
30 60 90
=>  210

3
18 11 19
4 13 7
1 8 13
=> 45


2
10 50 1
5 100 11
=> 110
*/
