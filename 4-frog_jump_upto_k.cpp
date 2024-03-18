#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
//////////////////////////////////////////////////////////////////////////////////////////
ll recursion(vector<ll> &height, ll n, ll k, ll index)
{
    if (index == (n - 1))
    {
        return 0;
    }
    ll minimum = INT_MAX;
    for (ll jump = 1; jump <= k; jump++)
    {
        ll cur = index + jump;
        if (cur < n)
        {
            minimum = min(minimum, abs(height[index] - height[cur]) + recursion(height, n, k, cur));
        }
    }
    return minimum;
}

//////////////////////////////////////////////////////////////////////////////////////////
ll memoization(vector<ll> &height, ll n, ll k, ll index, vector<ll> &mem_arr)
{
    if (index == (n - 1))
    {
        return 0;
    }
    if (mem_arr[index] != -1)
    {
        return mem_arr[index];
    }
    ll minimum = INT_MAX;
    for (ll jump = 1; jump <= k; jump++)
    {
        ll cur = index + jump;
        if (cur < n)
        {
            minimum = min(minimum, abs(height[index] - height[cur]) + memoization(height, n, k, cur, mem_arr));
        }
    }
    mem_arr[index] = minimum;
    return mem_arr[index];
}

//////////////////////////////////////////////////////////////////////////////////////////
ll dynamic(vector<ll> &height, ll n, ll k)
{
    vector<ll> dp(n);
    dp[n - 1] = 0;
    for (ll i = (n - 2); i >= 0; i--)
    {
        ll minimum = INT_MAX;
        for (ll jump = 1; jump <= k; jump++)
        {
            ll cur = i + jump;
            if (cur < n)
            {
                minimum = min(minimum, abs(height[i] - height[cur]) + dp[cur]);
            }
            else
            {
                break;
            }
        }
        dp[i] = minimum;
    }
    return dp[0];
}

///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> height(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << recursion(height, n, k, 0) << endl;
  
    vector<ll> mem_arr(n, -1);
    cout << memoization(height, n, k, 0, mem_arr) << endl;
  
    cout << dynamic(height, n, k) << endl;
    return 0;
}
