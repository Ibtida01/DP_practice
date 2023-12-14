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
int lcs(int i,int j)
{
    if(i==-1 || j==-1)
        return 0;//why return 0?? because i==-1 (or j==-1) means 1st string is an empty  string(if j==-1,then 2nd string, if both are -1, them both are empty strings)
        //and empty string has nothing in common, so answer will be 0
    if(mem[i][j]!=-1)
    if(mem[i][j]!=-1)
        return mem[i][j];
    if(s1[i]==s2[j])
    {
       // show.pb(s1[i]);
        mem[i][j]=1+lcs(i-1,j-1);
        return mem[i][j];
    }
    else {
        mem[i][j]=max(lcs(i-1,j),lcs(i,j-1));
        return mem[i][j];
    }
}
void solve()
{
    memset(mem,-1,sizeof(mem));
    cin>>s1>>s2;
    int ans=lcs(s1.size()-1,s2.size()-1);
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
