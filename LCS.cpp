#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);


string solve(string s , string t)
{
    const int len1= s.length();
    const int len2=t.length();

    int dp[len1+1][len2+1];

    for(int row=0;row<=len1;row++)
        dp[row][0]=0;
    for(int col=0;col<=len2;col++)
        dp[0][col]=0;


    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {

            if(s[i-1]==t[j-1])
            {
                dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i][j-1],dp[i-1][j]));

            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }


    int row=len1,col=len2;
    string ans="";
    while(row>0 && col>0)
    {
       if(s[row-1]==t[col-1] && (dp[row-1][col-1]+1)==dp[row][col])
       {
           ans.push_back(s[row-1]);
           row--;
           col--;
       }
       else if(dp[row][col]==dp[row][col-1])
            col--;
       else
            row--;


    }
    reverse(ans.begin(),ans.end());
    return ans;

}


int main()
{
	FASTIO;

	string s,t;
	 cin>>s>>t;
	 string ans=solve(s,t);
	 cout<<ans<<"\n";
	return 0;
}











