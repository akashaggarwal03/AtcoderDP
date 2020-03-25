#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);
#define mod 1000000007

ll solve(vector<vector<char> >mat,ll n,ll w)
{

    ll dp[n][w];
    dp[0][0]=1;
    int col=1;

    while(col <w && mat[0][col]=='.' )
    {
        dp[0][col]=1;
        col++;
    }

    while(col<w)
    {
        dp[0][col]=0;
        col++;
    }

    int row=1;

    while(row<n && mat[row][0]=='.' )
    {
        dp[row][0]=1;
        row++;

    }



    while(row<n)
    {
        dp[row][0]=0;
        row++;
    }


    for(int i=1;i<n;i++)
    {
        for(int j=1;j<w;j++)
        {
            if(mat[i][j]=='.')
            {
                dp[i][j]=(dp[i][j-1]%mod+ dp[i-1][j]%mod)%mod;

            }
            else
                dp[i][j]=0;

        }

    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<w;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/

    return dp[n-1][w-1];

}

int main()
{
	FASTIO;
	ll n,w;
	 cin>>n>>w;

	 vector<vector<char> >mat(n,vector<char>(w));

	 for(int i=0;i<n;i++)
        for(int j=0;j<w;j++)
            cin>>mat[i][j];

     ll ans=solve(mat,n,w);
	 cout<<ans%mod<<"\n";
	return 0;
}











