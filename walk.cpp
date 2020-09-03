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

void add_self(ll &a, ll b)
{
    a += b;
    if(a >= mod)
        a -= mod;

}
vector<vector<ll> > mul(vector<vector<ll> >A, vector<vector<ll> >B)
{
    ll n = A.size();

    vector<vector<ll> >res(n, vector<ll>(n,0));


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                res[i][j] =(res[i][j]+ A[i][k] * B[k][j])%mod;
            }
        }
    }

    return res;
}




vector<vector<ll> > pow(vector<vector<ll> > &mat, ll power)
{
   
    if(power==1)
        return mat;
    vector<vector<ll> >res=pow(mat,power/2);

     if(power&1LL)
        return mul(mul(mat,res),res);

    return mul(res,res);

}

ll solve(vector<vector<ll > >mat,ll k )
{
    vector<vector<ll> >ak=pow(mat,k);

    ll res=0;
    ll n=mat.size();
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            add_self(res,ak[i][j]);

    return res;

}


int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, k;
    cin >> n >> k;

    vector<vector<ll> >adj(n, vector<ll>(n));

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            cin >> adj[i][j];

    cout << solve(adj, k) << "\n";


    return 0;
}