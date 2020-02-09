//Dp with bitmasks easy
#include <bits/stdc++.h>
using namespace std;

const int N = 1005, cap = 1e9;

const int mask = 7; //max 111
const int VIT[] = { 1, 2, 4 }; //representing bits actually in mask.


//since N > vitamins count, so we have recursive substructure on distribution of medics to have all three vitamins bit set.
//and we have to count minm cost

int n, c[N], v[N], dp[N][mask], ans;
//dp[i][mask] = minm cost of taking all vitamins considering till ith medic and current mask.

int solve(int idx = 0, int vit = 0) //vit is actually mask, idx is for current medic
{
	if (vit == mask)
		return 0;

	if (idx >= n)
		return cap;

	int ret = dp[idx][vit];
	if (ret != -1)
		return ret;
    
    //two choices: not take current idx in that case mask remains as it is
    //second case: we take current idx, mask me set bit doing or with VIT[idx], also cost is added.

	return ret = min( solve(idx + 1, vit),   solve(idx + 1, vit | v[idx])+c[idx] );
}

signed main() 
{
	cin >> n;
	for (int i = 0; i < n; ++i) 
    {
		string s;
		cin >> c[i] >> s;
		for (char c : s) 
        {
			v[i] |= VIT[c - 'A'];
		}
	}
	memset(dp, -1, sizeof(dp));

	ans = solve();
	cout << (ans >= cap ? -1 : ans);
	return 0;
}
