#include"bits/stdc++.h"
using namespace std;

#define ll long long int
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define inf LLONG_MAX

int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<ll>vect(n + 1);
    vector<ll>cum_sum(n + 1, 0);
    f(i, 1, n + 1)
    {
        cin >> vect[i];
        cum_sum[i] = vect[i] + cum_sum[i - 1];
    }

    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);


    for(int i = 2; i <= n; i++)
    {
        int start = 1;
        int end = i;

        while(end <= n)
        {
            ll res = inf;

            for(int pivot = start; pivot < end; pivot++)
            {
                res = min(res, dp[start][pivot] + dp[pivot + 1][end] + cum_sum[pivot] - cum_sum[start - 1] + cum_sum[end] - cum_sum[pivot]);
            }
            dp[start][end] = res;

            start++;
            end++;
        }
    }

    cout << dp[1][n] << "\n";

    return 0;
}