#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);


int main()
{
	FASTIO;

	ll n;
	 cin>>n;

    //dp[i] denote the probability of getting i heads.
    double dp[n+1];
    dp[0]=1.0;

    for(int i=1;i<=n;i++)
    {
        double p_head;
         cin>>p_head;
         dp[i]=dp[i-1]*p_head;


        for(int j=i-1;j>0;j--)
        {
           dp[j]= p_head*dp[j-1] +(1.0-p_head)*dp[j];

        }
        dp[0]*=(1.0-p_head);
    }
    double ans=0.0;

    int index= (n+1)/2;
    for(int i=index;i<=n;i++)
        ans+=dp[i];

    cout<<setprecision(10)<<ans<<"\n";

	return 0;
}











