#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);

int main()
{
	FASTIO;
	ll n,k;
	 cin>>n>>k;
	 vector<ll>vect(n);
	 f(i,0,n)
        cin>>vect[i];


    //dp[i]-> is true if the player with first turn wins if the pile
    //contains i stones.

    vector<bool>dp(k+1,0);

    for(int stones=0;stones<=k;stones++)
    {
        for(int x:vect)
            if(x<=stones && !dp[stones-x])
                dp[stones]=true;
    }

    if(dp[k])
        cout<<"First\n";
    else
        cout<<"Second\n";



	return 0;
}











