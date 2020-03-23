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

ll solve(ll n,vector<ll>a,vector<ll>b,vector<ll>c)
{
    ll dp[n][3];
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];

    for(int i=1;i<n;i++)
    {

        for(int j=0;j<3;j++)
        {

            if(j==0)
            {
                dp[i][j]=max(a[i]+ dp[i-1][1],a[i]+dp[i-1][2]);

            }
            else if(j==1)
            {
               dp[i][j]=max(b[i]+ dp[i-1][0],b[i]+dp[i-1][2]);
            }
            else
            {
                dp[i][j]=max(c[i]+ dp[i-1][1],c[i]+dp[i-1][0]);
            }


        }
    }

    ll ans=-1;
    for(int j=0;j<3;j++)
        ans=max(ans,dp[n-1][j]);

    return ans;



}




int main()
{
	FASTIO;

	ll n;
	 cin>>n;
	 vector<ll>a(n);
	 vector<ll>b(n);
	 vector<ll>c(n);

	 for(int i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i];

     ll ans =solve(n,a,b,c);
     cout<<ans<<"\n";

	return 0;
}











