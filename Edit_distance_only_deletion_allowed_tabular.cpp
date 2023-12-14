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
int f(int l1,int l2)
{
    for(int i=0;i<=l2;i++)
        mem[0][i]=i;
    for(int j=0;j<=l1;j++)
        mem[j][0]=j;
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
                mem[i][j]=mem[i-1][j-1];
            else mem[i][j]=min(1+mem[i][j-1],1+mem[i-1][j]);//NOTICE THE CHANGE
        }
    }
    return mem[l1][l2];
}
void solve()
{
   // memset(mem,-1,sizeof(mem));
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
