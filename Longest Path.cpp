#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define sz(a) int((a).size())
#define mod 1000000007
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)

//MIN-MAX
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

//LCM
int lcm(int a, int b) {  return a * (b / __gcd(a, b)); }

//For sort by second
bool cmp(const pair<int,int> &a)
{ return a.first<a.second; }

//Tree
 const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];
bool visited[MAXN];
ll dp[MAXN];

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

void dfs(ll par)
{
    visited[par]=true;

    for(ll child:adj[par])
    {
        if(!visited[child])
            dfs(child);

        dp[par]= max(dp[par],1+dp[child]);

    }

}
int main()
{
	ll n,m;
	 cin>>n>>m;

	 f(i,0,m)
	 {
	     ll x,y;
	      cin>>x>>y;
	      adj[x].push_back(y);

	 }

	 for(ll i=1;i<=n;i++)
     {
        if(!visited[i])
            dfs(i);

     }
     ll ans=0;

     for(ll i=0;i<=n;i++)
     {
         ans=max(ans,dp[i]);
     }

     cout<<ans<<"\n";

	return 0;
}











