#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
//////////////////////////////////////////////////////////////////////////////
////////////////////////////---RECURSION---///////////////////////////////////
ll recursion(ll target)
{
    if (target == 0)
    {
        return 1;
    }
    ll o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0;
    if (target >= 1)
    {
        o1 = recursion(target - 1);
    }
    if (target >= 2)
    {
        o2 = recursion(target - 2);
    }
    if (target >= 3)
    {
        o3 = recursion(target - 3);
    }
    if (target >= 4)
    {
        o4 = recursion(target - 4);
    }
    if (target >= 5)
    {
        o5 = recursion(target - 5);
    }
    if (target >= 6)
    {
        o6 = recursion(target - 6);
    }
    return (o1 + o2 + o3 + o4 + o5 + o6) % mod;
}

//////////////////////////////////////////////////////////////////////////////
///////////////////////////---memoization---//////////////////////////////////
ll memoization(ll target, vector<ll> &memo_Arr)
{
    if (target == 0)
    {
        return 1;
    }
    if (memo_Arr[target] == -1)
    {
        ll o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0;
        if (target >= 1)
        {
            o1 = memoization(target - 1, memo_Arr);
        }
        if (target >= 2)
        {
            o2 = memoization(target - 2, memo_Arr);
        }
        if (target >= 3)
        {
            o3 = memoization(target - 3, memo_Arr);
        }
        if (target >= 4)
        {
            o4 = memoization(target - 4, memo_Arr);
        }
        if (target >= 5)
        {
            o5 = memoization(target - 5, memo_Arr);
        }
        if (target >= 6)
        {
            o6 = memoization(target - 6, memo_Arr);
        }
        memo_Arr[target] = (o1 + o2 + o3 + o4 + o5 + o6) % mod;
    }
    return memo_Arr[target];
}

//////////////////////////////////////////////////////////////////////////////
////////////////////--------- Dp approach ---------///////////////////////////

ll dynamic(ll target)
{
    vector<ll> dp(target + 1);
    dp[0] = 1;
    for (ll i = 1; i <= target; i++)
    {
        ll sumlast6 = 0;
        for (ll j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                sumlast6 += dp[i - j];
            }
        }
        dp[i] = sumlast6 % mod;
    }
    return dp[target];
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int main()
{
    ll target;
    cin >> target;
    // cout << recursion(target) << endl;
   
    // vector<ll> memo_Arr(target + 1, -1);
    // cout << memoization(target, memo_Arr) << endl;

    // cout << dynamic(target) << endl;
    return 0;
}
