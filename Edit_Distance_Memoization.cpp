#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#include<cstring>
#define dbg(x) cout << #x << " = " << x << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define MAX 1000000000
#define pii pair<int,int>
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
string s1,s2;
string show;
int mem[1001][1001];
int f(int i,int j)
{
    if(i==0)
        return j;
    else if(j==0)
        return i;
    //else
    if(mem[i][j]!=-1)
        return mem[i][j];
    if(s1[i-1]==s2[j-1])
    {
        mem[i][j]=f(i-1,j-1);
        return mem[i][j];
    }
    else {
            int x=1+f(i-1,j);
            int y=1+f(i,j-1);
            int z=1+f(i-1,j-1);
            mem[i][j]=min(min(x,y),z);
            return mem[i][j];
    }
}

void solve()
{
    memset(mem,-1,sizeof(mem));
    cin>>s1>>s2;
    int ans=f(s1.size(),s2.size());
    cout<<ans<<endl;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    //fast_io;
   // int t;
    //cin>>t;
//    for(int i=1;i<=t;i++)
    //while(t--)
        solve();
}
