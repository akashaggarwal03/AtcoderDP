#include"bits/stdc++.h"
using namespace std;

#define ll long long int
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define sz(a) int((a).size())
#define mod 1000000007
#define inf LLONG_MAX
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
template <typename T>
inline T gcd(T a, T b)
{
    while (b != 0) swap(b, a %= b);
    return a;
}

template <typename T>
inline void seethis(vector<T>vect)
{
    for(T x : vect)
        cout << x << " ";
    cout << "\n";
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//LCM
int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

//For sort by second
bool cmp(const pair<int, int> &a)
{
    return a.first < a.second;
}

//Tree
/* const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];*/

//ModPower
ll modpower(ll a, ll b, ll c)
{
    ll res = 1;
    while(b)
    {
        if(b & 1LL)
            res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}
ll dp[22][1 << 22];
ll can[22][22];
ll solve(ll men, ll woman_subset, ll n)
{
    if(men == n)
    {
        if(woman_subset == 0)
            return 1;
        else
            return 0;
    }

    if(dp[men][woman_subset] != -1)
        return dp[men][woman_subset];


    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        if(can[men][i] and ((woman_subset) & (1 << i)))
        {
            res = (res % mod + solve(men + 1, woman_subset ^ (1 << i), n) % mod) % mod;
        }
    }
    //cout<<"sabquwshfduiqw";

    return dp[men][woman_subset] = res;

}
int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;


    memset(dp, -1, sizeof dp);



    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> can[i][j];

    cout << solve(0, ((1 << n) - 1), n) << "\n";

    return 0;
}