#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll recursion(ll n, ll step)
{
    if (step >= (n - 1))
    {
        return 1;
    }
    return recursion(n, step + 1) + recursion(n, step + 2);
}
ll memoization(ll n, ll step, vector<ll> &mem)
{
    if (step >= (n - 1))
    {
        return 1;
    }
    if (mem[step] == -1)
    {
        mem[step] = memoization(n, step + 1, mem) + memoization(n, step + 2, mem);
    }
    return mem[step];
}
ll dynamic(ll n)
{
    vector<ll> dp(n + 1);
    dp[n] = 1, dp[n - 1] = 1;
    for (ll step = (n - 2); step >= 0; step--)
    {
        dp[step] = dp[step + 1] + dp[step + 2];
    }
    return dp[0];
}
int main()
{
    ll n;
    cin >> n;
    cout << recursion(n, 0) << endl;
    vector<ll> mem(n + 1, -1);
    cout << memoization(n, 0, mem) << endl;

    cout << dynamic(n) << endl;
    return 0;
}
