#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007


///////////////////////////////////////////////////////////////////////////////
ll recursion(vector<ll> &height, ll index, ll n)
{
    if (index >= (n - 2))
    {
        return abs(height[index] - height[n - 1]);
    }
    ll ans1 = abs(height[index] - height[index + 1]) + recursion(height, index + 1, n);
    ll ans2 = abs(height[index] - height[index + 2]) + recursion(height, index + 2, n);
    return min(ans1, ans2);
}


///////////////////////////////////////////////////////////////////////////////
ll memoization(vector<ll> &height, ll index, ll n, vector<ll> &mem_Arr)
{
    if (index >= (n - 2))
    {
        return abs(height[index] - height[n - 1]);
    }
    if (mem_Arr[index] != -1)
    {
        return mem_Arr[index];
    }
    ll ans1 = abs(height[index] - height[index + 1]) + memoization(height, index + 1, n, mem_Arr);
    ll ans2 = abs(height[index] - height[index + 2]) + memoization(height, index + 2, n, mem_Arr);
    mem_Arr[index] = min(ans1, ans2);
    return mem_Arr[index];
}


///////////////////////////////////////////////////////////////////////////////
ll dynamic(vector<ll> &height, ll n)
{
    vector<ll> dp(n);
    dp[n - 1] = 0;
    for (ll i = (n - 2); i >= 0; i--)
    {
        if (i == (n - 2))
        {
            dp[i] = abs(input[i] - input[n - 1]);
        }
        else
        {
            ll ans1 = abs(input[i] - input[i + 1]) + dp[i + 1];
            ll ans2 = abs(input[i] - input[i + 2]) + dp[i + 2];
            dp[i] = min(ans1, ans2);
        }
    }
    return dp[0];
}


int main()
{
    ll n;
    cin >> n;
    vector<ll> height(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << recursion(height, 0, n) << endl;
    vector<ll> mem_Arr(n, -1);
    cout << memoization(height, 0, n, mem_Arr) << endl;

    cout << dynamic(height, n) << endl;
    return 0;
}
