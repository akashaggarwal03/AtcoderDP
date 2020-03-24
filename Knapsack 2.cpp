#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);
#define inf 1e18 +5;
ll solve(ll no_of_items,ll knap_cap, vector<ll>val,vector<ll>wt,ll sum_val)
{
    ll dp[sum_val+1][no_of_items+1];



    for(ll row=0;row<=sum_val;row++)
        dp[row][0]=inf;
    for(ll col=0;col<=no_of_items;col++)
        dp[0][col]=0;


     ll ans= -1;
    for(ll i=1;i<= sum_val;i++)
    {
        for(ll j=1;j<=no_of_items;j++)
        {

            if(i>=val[j-1])
            {
                dp[i][j]= min(dp[i-val[j-1]][j-1]+wt[j-1],dp[i][j-1]);
            }
            else
            {
               dp[i][j]=dp[i][j-1];
            }

            if(dp[i][j]<=knap_cap )
            {
               /* watch(dp[i][j]);
                watch(knap_cap);
                watch(i);
                watch(ans);*/
                 ans=max(ans,i);
            }


        }


    }




    return ans;

}

int main()
{

	ll no_of_items,knap_cap;

	 cin>>no_of_items>>knap_cap;

	 vector<ll>val(no_of_items);
	 vector<ll>wt(no_of_items);

	 ll sum_val=0;

	 f(i,0,no_of_items)
	 {
	     cin>>wt[i]>>val[i];
	     sum_val+=val[i];
	 }

	ll ans=solve(no_of_items,knap_cap,val,wt,sum_val);

	cout<<ans<<"\n";

	return 0;
}











