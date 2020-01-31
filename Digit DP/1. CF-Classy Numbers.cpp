//Beauty of DP is that code is less, once you realise the concept.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dp[20][5][2];
string s;
int l,r;
int go(int pos, int cnt, int tight)
{
    if(pos == (int)s.size())
    {
        //did optimisation as cnt<=3 isnt required as 
        //we wont call next dp only if cnt exceeds 3
        return 1;
    }

    if(dp[pos][cnt][tight] != -1)
    {
        return dp[pos][cnt][tight];
    }

    int ret=0;
    int end = tight? (s[pos]-'0'): 9;

    for(int i=0; i<=end; i++)
    {
        //updated value of cnt
        int cntupd = cnt + (i > 0); //classy nos condition

        if(cntupd <= 3)
        {
            ret = ret + go(pos+1, cntupd, tight & (i == end));
        }
    }
    return dp[pos][cnt][tight] = ret;

} 


void solve()
{
    cin>>l>>r;

    s = to_string(r);
    memset(dp, -1, sizeof dp);
    int ans1 = go(0, 0, 1);

    s = to_string(l-1);
    memset(dp, -1, sizeof dp);
    int ans2 = go(0, 0, 1);
    int ans = ans1 - ans2;
    cout<<ans<<endl;
}

signed main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
