#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

///////////////////////////////////////////////////////////////////////
ll recursion(vector<ll> &input, ll n, ll index)
{
    if (index >= n)
    {
        return 0;
    }
    ll notake = recursion(input, n, index + 1);
    ll take = recursion(input, n, index + 2) + input[index];
    return max(take, notake);
}

////////////////////////////////////////////////////////////////////////
ll memoization(vector<ll> &input, ll n, ll index, vector<ll> &mem_arr)
{
    if (index >= n)
    {
        return 0;
    }
    if (mem_arr[index] != -1)
    {
        return mem_arr[index];
    }
    ll notake = memoization(input, n, index + 1, mem_arr);
    ll take = memoization(input, n, index + 2, mem_arr) + input[index];
    mem_arr[index] = max(take, notake);
    return mem_arr[index];
}

////////////////////////////////////////////////////////////////////////
ll dynamic(vector<ll> &input, ll n)
{
    if (n > 1)
    {
        vector<ll> dp(n);
        dp[n - 1] = input[n - 1];
        dp[n - 2] = max(input[n - 1],input[n - 2]);
        for (ll i = (n - 3); i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], input[i] + dp[i + 2]);
        }
        return dp[0];
    }
    else
    {
        return input[0];
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> input(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << recursion(input, n, 0) << endl;

    vector<ll> mem_arr(n, -1);
    cout << memoization(input, n, 0, mem_arr) << endl;

    cout << dynamic(input, n) << endl;
    return 0;
}
/*
3
1 2 4
=> 5

4
2 1 4 9
=> 11

9
1 2 3 1 3 5 8 1 9
=> 24

5
1 2 3 5 4
=> 8

5
3 2 5 10 7
=> 15

6
5 5 10 100 10 5
=> 110
*/
