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
