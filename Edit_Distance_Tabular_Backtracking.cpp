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
string s1,s2;
string show1,show2;
int mem[1001][1001];

//int lcs(int i,int j)
//{
//    if(i==0)
//        return j;
//    else if(j==0)
//        return i;
//    //else
//    if(mem[i][j]!=-1)
//        return mem[i][j];
//    if(s1[i-1]==s2[j-1])
//    {
//        mem[i][j]=lcs(i-1,j-1);
//        return mem[i][j];
//    }
//    else
//    {
//        int x=3+lcs(i-1,j);
//        int y=3+lcs(i,j-1);
//        int z=2+lcs(i-1,j-1);
//        mem[i][j]=min(min(x,y),z);
//        return mem[i][j];
//    }
//}
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
            else mem[i][j]=min(min(1+mem[i][j-1],1+mem[i-1][j]),1+mem[i-1][j-1]);
        }
    }
    return mem[l1][l2];
}
//as long as we are considering the cost of inDel (insertion OR deletion) and Replace same(here 1), we dont need to think about anything else
//this code has a generalized version too,having c_i,c_d,c_r standing respectively for costs for insertion ,deletion and replace
void backTrack()
{
    for(int i=s1.size(),j=s2.size(); i>=0 || j>=0;)
    {
        if(s1[i-1]==s2[j-1])
        {
            show1.push_back(s1[i-1]);
            show2.push_back(s2[j-1]);
            --i,--j;
        }
        else
        {
            if(mem[i][j]==mem[i][j-1]+3)// <--- GOING TOWARDS THE LEFT CELL
            {
                //means insertion of the current character of 2nd string to the 1st string( the string that goes vertically downward in the DP table)
                // RO_SE  _ --> indicates the insertion of R (current char of the 2nd string ,HORSE) to the 1st string
                // HORSE
                //going left on the DP table from the current cell
                show1.push_back('_');
                show2.push_back(s2[j-1]);
                --j;
                //NB:this step can alternatively mean insertion too,like insertion of R (at the _ place) to the 1st string,I am explaining everything with respect to 2nd string
            }
            else if(mem[i][j]==mem[i-1][j]+3)// GOING UPWARDS IN THE DP TABLE
            {
                //means the deletion of the current char of the 1st string and go backward by 1 step in the 2nd string(as we are deleting in the 1st string,
                //due to shifting,1st index won't move
                // "___If___" the 1st string is HORSE and the 2nd one is ROSE (for better explanation)
                //  HORSE
                //  RO_SE
                // '_' --> here the space in HORSE and the missing of R indicates , R has been deleted from the 1st string
                // so ...
                show1.push_back(s1[i-1]);//deletion from the 2nd string is equivalent to adding a '_' char into the 1st string
                show2.push_back('_');
                --i;
                //alternatively this can me insertion of the current character of the 1st string to the 2nd string too,depends on perspective
            }
            else
            {
                //it is for i-1 and j-1
                //when s1[i-1]!=s2[j-1] && we go i-1 and j-1, this means we have replaced in one of the strings
                //  HORSE
                //  RO_SE --> either H replaced by R OR R replaced by H ...both have same effect, no worries :)
                show1.push_back(s1[i-1]);
                show2.push_back(s2[j-1]);
                --i,--j;
            }
        }
    }
}

void solve()
{
    memset(mem,-1,sizeof(mem));
    cin>>s1>>s2;
    int ans=f(s1.size(),s2.size());
    cout<<ans<<endl;
    backTrack();
    reverse(show1.begin(),show1.end());
    reverse(show2.begin(),show2.end());
    cout<<show1<<endl;
    cout<<show2<<endl;
    cout<<"DP Table:"<<endl;
    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
            cout<<mem[i][j]<<" ";
        cout<<endl;
    }
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
//Try some test cases like: HORSE, ROSE ;  BANGLADESH, ANGLE etc.
