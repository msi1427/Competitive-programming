#include<bits/stdc++.h>
using namespace std;

string s;
int dp[10][10];

int lps(int i,int j)
{
    if(i==j) return dp[i][j]=1;
    if(s[i]==s[j] && i+1==j) return dp[i][j]=2;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=lps(i+1,j-1)+2;
    return dp[i][j]=max(lps(i,j-1),lps(i+1,j));
}

int main()
{
    cin >> s;
    memset(dp,-1,sizeof(dp));
    cout << lps(0,s.size()-1) << "\n";
}
