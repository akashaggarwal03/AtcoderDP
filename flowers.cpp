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
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

template <typename T>
inline void seethis(vector<T>vect)
{
    for(T x:vect)
        cout<<x<<" ";
    cout<<"\n";
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//LCM
int lcm(int a, int b) {  return a * (b / gcd(a, b)); }

//For sort by second
bool cmp(const pair<int,int> &a)
{ return a.first<a.second; }

//Tree
/* const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];*/

//ModPower
ll modpower(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1LL)
            res=(res*a)%c;
        a=(a*a)%c;
        b>>=1;
    }
    return res;
}


ll solve(ll n,ll height[],ll beauty[])
{


    //Dp[i]->maximum beauty for a subsequence which ends at ith flower:
    ll dp[n];
    dp[0]=beauty[0];

    //We maintain a map with key as height as we know height is always distinct:
    //To maintain a structure in which if height[i]< height[j] then dp[i]<dp[j];
    map<ll,ll>mp;

    mp[height[0]]=dp[0];

    for(ll i=1;i<n;i++)
    {
        dp[i]=beauty[i];
        auto it=mp.upper_bound(height[i]);

        if(it!=mp.begin())
        {
            --it;
            dp[i]+= it->second;
        }

        mp[height[i]]=dp[i];

        it=mp.upper_bound(height[i]);

        while(it!=mp.end() and it->second<dp[i])
        {
            auto temp=it;
            temp++;
            mp.erase(it);
            it=temp;
        }
       
    }


    return *max_element(dp,dp+n);

}


int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    ll n;
     cin>>n;

     ll height[n];

     for(ll i=0;i<n;i++)
        cin>>height[i];

    ll beauty[n];

    for(ll i=0;i<n;i++)
        cin>>beauty[i];

    cout<<solve(n,height,beauty)<<"\n";
    
    return 0;
}