#include<bits/stdc++.h>
using namespace std;
#define NUM 1000005
long long phi[NUM];
void phi_seive()
{
    for(long long i=1;i<NUM;i++) phi[i]=i;
    for(long long i=2;i<NUM;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(long long j=2*i;j<NUM;j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
    return;
}
int main()
{
    phi_seive();
    for(long long i=1;i<=99;i++) cout<<i<<" " << phi[i]<< endl;
}
///// Actual for any 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll phi(ll n)
{
    ll res=0;
    if (n==1) return 1;
    res=n;
    if (n%2==0)
    {
        res-=res/2;
        while (n%2==0) n/=2;
    }
    for (ll j=3; j*j<=n; j+=2)
    {
        if (n%j==0)
        {
            res-=res/j;
            while (n%j==0) n/=j;
        }
    }
    if (n>1) res-=res/n;
    return res;
}
ll N;
int main()
{
    cin >> N;
    cout << phi(N) << endl;
}
