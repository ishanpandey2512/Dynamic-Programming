#include "bits/stdc++.h"
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#define int                      long long
#define ll                       long long
#define ld                       long double
#define ull                      unsigned long long
#define vi                       vector<int>
#define pii                      pair<int,int>
#define mod                      1000000007 //998244353

#define for0(i,n)                for(int i=0;i<n;++i)
#define fora(i,a,b)              for(int i=a;i<=b;++i)
#define rfor(i,a,b)              for(int i=a;i>=b;--i)
#define onlyunique(v)            v.erase(unique(all(v)), v.end()); //only for sorted vector
#define rev(v)                   reverse(v.begin(),v.end())

#define sz(tmp)                  (int)tmp.size()
#define def(v)                   memset(v, -1, sizeof(v));
#define def0(v)                  memset(v, 0, sizeof(v));
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()
#define f                        first
#define s                        second
#define pb                       push_back
#define mp                       make_pair
#define pie                      (3.141592653589)
#define inf                      ((ll)7000000000000000000)
#define um                       unordered_map

#define ordered_set             tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//0-based idxing, methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

#ifndef ONLINE_JUDGE
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}
#else
#define dbg(...) 50
#endif


void ishan_pandey()
{   //input fastio
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
int dxx[4] = { 0 , -1 , 0 , 1 };
int dyy[4] = { 1 ,  0 , -1 ,  0 };
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int n;
int mo = 100;
ll a[1100];
ll dp[1100][1100];

//returns color of resulting mixture from s to e mixed
ll csum(int s, int e)
{
    ll ans = 0;
    for (int i = s; i <= e; i++)
    {
        ans = (ans + a[i]) % 100;
    }
    return ans;
}


//mixing (summing) all mixtures from lo to hi will have a unique no(color)-> unique smoke bhi generate hoga yhi dp me stored hai
ll solveMixtures(int lo, int hi)
{
    if (lo >= hi) return dp[lo][hi] = 0; //smke generated is 0;

    if (dp[lo][hi] != -1) return dp[lo][hi];


    ll result  = INT_MAX;

    for (int i = lo; i < hi; i++)
    {
        ll ans = (solveMixtures(lo, i) + solveMixtures(i + 1, hi) + (csum(lo, i) * csum(i + 1, hi)));

        result = min(result, ans);
    }
    return dp[lo][hi] = result;
}



// void solve()
// {

// }
int main()
{
    // clock_t t1, t2;
    // t1 = clock();

    // ishan_pandey();
    // int t = 1;
    // //cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
    //     solve();
    //     // cout << "Case" << " " << "#" << i << ":" << " " << ans << endl;
    // }

    //readtill EOL
    while (scanf("%d", &n) != EOF)
    {

        memset(dp, -1, sizeof dp);

        for0(i, n) cin >> a[i];

        cout << solveMixtures(0, n - 1) << endl;
    }

    return 0;
}




