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
ll dp[10001][101][2];

void add_self(ll &a, ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}

ll solve(string &s, int D, int pos, int d, int tight)
{


    if(dp[pos][d][tight] != -1)
        return dp[pos][d][tight];

    int choices = (tight) ? (s[pos] - '0') : 9;

    if(pos == (int(s.length())-1))
    {
        ll res = 0;
        for(int x = 0; x <= choices; x++)
            if((x % D) == d)
                res++;
        return res;
    }


    ll res = 0;
    for(int x = 0; x <= choices; x++)
    {
        add_self(res, solve(s, D, pos + 1, (D + d - x % D) % D, tight and (x == choices)));
    }

    return dp[pos][d][tight] = res;

}


int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string k;
    cin >> k;
    int d;
    cin >> d;
     memset(dp, -1, sizeof dp);
    ll ans = solve(k, d, 0, 0, 1);
   
    cout << (ans-1+mod)%mod << "\n";



    return 0;
}