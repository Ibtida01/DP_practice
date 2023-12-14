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
#define EPS 1e-9
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
bool isEqualD(double x,double y)
{
    return (abs(x-y)<EPS) ? true : false;
}
string show;
int mem[1001][1001];
/*
Using it for Memoized version might cause Runtime Error
  */
int lcsbsqBUp(int lenth1,int lenth2,string s1,string s2)
{

    for(int i=0;i<=lenth1;i++)
        mem[i][0]=0;
    for(int i=0;i<=lenth2;i++)
        mem[0][i]=0;
    for(int i=1;i<=lenth1;i++)
    {
        for(int j=1;j<=lenth2;j++)
        {
            if(s1[i-1]==s2[j-1])
                mem[i][j]=1+mem[i-1][j-1];
            else mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
        }
    }
    return mem[lenth1][lenth2];
}
void backtrack(string s1,string s2)
{
    show.clear();
    for(int i=s1.size(),j=s2.size();i>=0 || j>=0;)
    {
        if(s1[i-1]==s2[j-1])
            {
                show.push_back(s1[i-1]);
                --i,--j;
            }
        else{
            if(mem[i][j]==mem[i][j-1])
            {
                //came from left cell
                --j;
            }
            else{
                //came from upper cell
                --i;
            }
        }
    }
}
void solve()
{
    string s1,s2;
    memset(mem,-1,sizeof(mem));
    cin>>s1>>s2;
    int ans=lcsbsqBUp(s1.size(),s2.size(),s1,s2);
    cout<<ans<<endl;
    backtrack(s1,s2);
    reverse(show.begin(),show.end());
    cout<<show<<endl;
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
