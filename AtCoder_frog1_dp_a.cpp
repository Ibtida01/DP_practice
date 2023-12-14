    #include <bits/stdc++.h>
    #include <iostream>
    #include <cmath>
    #include<iomanip>
    #define dbg(x) cout << #x << " = " << x << endl;
    #define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
    #define pans cout << ans << "\n";
    #define endl "\n"
    #define pb push_back
    #define mp make_pair
    #define MAX 1000000000
    #define pii pair<int,int>
    #define EPS 1e-9
    // const ll mod=1e9+7;
    typedef long long int ll;
    typedef unsigned long long int ull;
    typedef long double ld;
    using namespace std;
    int dp[(ll)1e5];
    int f(int idx,vector<int>& h)
    {
        if(dp[idx]!=-1) return dp[idx];
        if(idx==0) return 0;
        int left=f(idx-1,h)+abs(h[idx]-h[idx-1]);
        int right;
        if(idx>=2)
        right=f(idx-2,h)+abs(h[idx]-h[idx-2]);
        else right=INT_MAX;
        return dp[idx]=min(left,right);
    }
    void solve() {
        int n;
        cin>>n;
        memset(dp,-1, sizeof(dp));
        vector<int> h(n);
        for(auto& it:h)
            cin>>it;
        cout<<f(n-1,h)<<endl;
    }

    int main()
    {
         //fast_io;
        // int t;
        // cin>>t;
        // while(t--)
           solve();
    }
