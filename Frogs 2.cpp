#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)

ll solve(vector<ll>vect,ll n,ll k)
{
   vector<ll>dp(n,0);
   dp[0]=0;
   dp[1]=abs(vect[0]-vect[1]);

   for(int i=2;i<n;i++)
   {
       ll j=i-1;
       dp[i]=1e18;
       ll temp_ans;

       while(j>=0 && j>=i-k )
       {

           temp_ans= abs(vect[j]-vect[i])+dp[j];
           dp[i]=min(temp_ans,dp[i]);
           j--;

       }

   }

    return dp[n-1];

}


int main()
{

	ll n,k;
	 cin>>n>>k;
	 vector<ll>vect(n);
	 f(i,0,n)
        cin>>vect[i];

    ll ans=solve(vect,n,k);
    cout<<ans<<"\n";

	return 0;
}











