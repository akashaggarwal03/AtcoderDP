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

ll solve(vector<ll>vect,ll n)
{
   vector<ll>dp(n,0);
   dp[0]=0;
   dp[1]=abs(vect[0]-vect[1]);

   {
   for(int i=2;i<n;i++)

       dp[i]=min(abs(vect[i-2]-vect[i])+dp[i-2],abs(vect[i-1]-vect[i])+dp[i-1]);


   }

    return dp[n-1];

}


int main()
{
	FASTIO;
	ll n;
	 cin>>n;
	 vector<ll>vect(n);
	 f(i,0,n)
        cin>>vect[i];

    ll ans=solve(vect,n);
    cout<<ans<<"\n";

	return 0;
}











