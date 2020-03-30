#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

int n,m;
int dp[105][105];
vector< int > mat;

int call(int x,int y){
    if(x+1>=y) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    int mn = INT_MAX;
    for(int i=x+1;i<=y-1;i++){
        int cc = call(x,i)+mat[x]*mat[i]*mat[y]+call(i,y);
        mn = min(mn,cc);
    }
    return dp[x][y]=mn;
}

int main(){
    while(cin>>n){
    mat.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    cout << call(0,n-1) << "\n";
    }
}
/*
5
5
4
6
2
7
*/
