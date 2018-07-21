#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int a[MAX];
int tree[MAX*3];
int mx;
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        mx=max(node,mx);
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[node]=tree[l]+tree[r];
    mx=max(node,mx);
}
int query(int node,int b,int e,int i, int j)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    int p1=query(l,b,m,i,j);
    int p2=query(r,m+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int n_v)
{
    if(i>e || i<b) return;
    if(b>=i && e<=i)
    {
        tree[node]=n_v;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    update(l,b,m,i,n_v);
    update(r,m+1,e,i,n_v);
    tree[node]=tree[l]+tree[r];
}
int main()
{
    int n,i,j;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    init(1,1,n);
    cin >> i >> j;
    cout << query(1,1,n,i,j) << endl;
    update(1,1,n,2,2);
    cout << query(1,1,n,i,j) << endl;
}
