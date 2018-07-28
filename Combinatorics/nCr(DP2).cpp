#include<bits/stdc++.h>
using namespace std;
int table[20][20];
int nCr(int n,int r)
{
    if(r==1) return n;
    else if(n==r) return 1;
    else if(table[n][r]!=-1) return table[n][r];
    else
    {
        table[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
        return table[n][r];
    }
}
int main()
{
    memset(table,-1,sizeof(table));
    int n=6,r=0;
    printf("%d",nCr(n,r));
}
