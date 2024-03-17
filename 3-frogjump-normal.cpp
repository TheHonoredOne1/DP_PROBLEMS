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
    dp[n - 2] = abs(height[n - 1] - height[n - 2]);
    for (ll i = (n - 3); i >= 0; i--)
    {
        ll t1 = abs(height[i] - height[i + 1]);
        ll t2 = abs(height[i] - height[i + 2]);
        ll x = min(t1 + dp[i + 1], t2 + dp[i + 2]);
        dp[i] = x;
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
