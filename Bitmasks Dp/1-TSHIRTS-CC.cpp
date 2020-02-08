#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define DEBUG false

int stoi(string &s){
    stringstream ss(s);
    int x;
    ss>>x;
    return x;
}

int ALL_PERSON;
ll dp[1025][102];
vector<vector<int> > v;

///mask denotes set of people who have got the t-shirts(unique)
///tid the current t-shirt we are going to give to some person who has this tshirt in almirah
ll calc(int mask,int tid){
    if(mask==ALL_PERSON){
        return 1;
    }
    ///ALl tshirts exhausted
    if(tid==101){
        return 0;
    }
    if(dp[mask][tid]!=-1){
        return dp[mask][tid];
    }

    ll ans = 0;

    ///Current tid is not alloted to anyone ( more tshirts less people )
    ans = calc(mask,tid+1);

    ///Allot the current to tshirt to someone who has that tshirt in almirah, but is not given a tshirt yet

    for(int p:v[tid]){
        if((mask&(1<<p))==0){
            ans += calc((mask|(1<<p)),tid+1);
        }
    }
    ans %= MOD;

    dp[mask][tid] = ans;
    return ans;
}






int main(){


    v.reserve(110);
    int t;
    cin>>t;

    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;

        ALL_PERSON = (1<<n) - 1;

        string s;
        for(int i=0;i<=100;i++){
            v[i].clear();
        }

        cin.get();
        ///Created the Reverse Mapping from the input
        for(int i=0;i<n;i++){
            getline(cin,s);
            stringstream ss(s);
            string temp;
            while(ss>>temp){
                v[stoi(temp)].push_back(i);

            }

        }


        for(int i=0;i<=100;i++){

            sort(v[i].begin(),v[i].end());
            if(v[i].size()>0 && DEBUG){

                cout<<"T-Shirt "<<i<<" -> ";
                for(auto j:v[i]){
                    cout<<j+1<<",";
                }
                cout<<endl;
            }
        }
        cout<<calc(0,1)<<endl;
    }
return 0;
}

