#include<bits/stdc++.h>
using namespace std;

int kadane(int a[], int n)
{
    int mtn=0, meh=0; //maxtillnow, maxendinghere
    for(int i=0; i<n; i++)
    {
        meh = max(meh+a[i], a[i]);

        if(meh > mtn)
            mtn = meh;
    }
    return mtn;
}

void solve() //gives max circular sum
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];

    int max_kad = kadane(a, n);
    //now find maxm sumof subarrays that contain corner elements
    //how: calc sum of complete array and keep reversing array elements sign
    int pura_wrap=0;
    for(int i=0; i<n; i++)
    {
        pura_wrap += a[i];
        a[i] = -a[i];
    }
    //max sum with corner elements will be:  
    pura_wrap = pura_wrap + kadane(a, n);

    if(max_kad > pura_wrap)
    {
        cout<<max_kad<<endl;

    }
    else
    {
        cout<<pura_wrap<<endl;
    }

}

signed main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
