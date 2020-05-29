#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mp make_pair
#define pb push_back
#define psi pair<string, int>
#define fi first
#define se second

psi dp[20][2][2][2]; //pos, tight1, tight2, (startmark - st)
string a, b;

psi solve(int pos, int t1, int t2, int st)
{
    if(pos == (int)a.size()) return {"", 1};

    if(dp[pos][t1][t2][st].se != -1) return dp[pos][t1][t2][st];

    int ret=-1;
    string ans="";
    //lb
    int st1 = t1 ? (a[pos]-'0'):0;
    //ub
    int en = t2 ? (b[pos]-'0'):9;

    for(int i=st1; i<=en; i++)
    {
        int val;
        if(st == 0 and i == 0)
        {
            val = 1;
        }
        else
            val = i;
            
            
            //start condition also embedded
        psi dpans = solve(pos+1, t1 & (i==st1), t2 & (i==en), st | (i>0));

        if(val * dpans.se > ret)
        {
             ret = val*dpans.se;
            //appending to ans if only no leading zeroes
            if(st == 0 and i == 0)
            {
                ans = dpans.fi;
            }
            else
            {
                reverse(dpans.fi.begin(), dpans.fi.end());
                dpans.fi.pb('0'+i);
                reverse(dpans.fi.begin(), dpans.fi.end());
                ans = dpans.fi;
            }
        } 
        //ret = max(ret, val * solve(pos+1, t1&(i==st1), t2&(i==en), st|(i>0)));
    }
    return dp[pos][t1][t2][st] = mp(ans, ret);
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    dp[i][j][k][l].se = -1;
                }
            }
        }
    }

    cin>>a>>b;
    reverse(a.begin(), a.end());
    while(a.size() < b.size())
    {
        a.pb('0');
    }
    reverse(a.begin(), a.end());
    
    psi ans = solve(0, 1, 1, 0);

    cout<<ans.fi<<endl;
    return 0;
}
