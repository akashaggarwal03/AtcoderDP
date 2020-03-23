#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);

ll solve(ll no_of_items,ll knap_cap, vector<ll>val,vector<ll>wt)
{
    ll dp[knap_cap+1][no_of_items+1];

    for(ll col=0;col<=no_of_items;col++)
        dp[0][col]=0;

    for(ll row=0;row<=knap_cap;row++)
        dp[row][0]=0;


    for(ll i=1;i<= knap_cap;i++)
    {
        for(ll j=1;j<=no_of_items;j++)
        {

            if(i>=wt[j-1])
            {

                dp[i][j]= max(dp[i-wt[j-1]][j-1]+val[j-1],dp[i][j-1]);
            }
            else
                dp[i][j]=dp[i][j-1];

        }

    }



    return dp[knap_cap][no_of_items];

}

int main()
{

	ll no_of_items,knap_cap;

	 cin>>no_of_items>>knap_cap;

	 vector<ll>val(no_of_items);
	 vector<ll>wt(no_of_items);

	 f(i,0,no_of_items)
	 {
	     cin>>wt[i]>>val[i];
	 }

	ll ans=solve(no_of_items,knap_cap,val,wt);

	cout<<ans<<"\n";

	return 0;
}











