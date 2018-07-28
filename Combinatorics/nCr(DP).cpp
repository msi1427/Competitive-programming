#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000003
ll fact[1000009];
ll bmod(ll B,ll P)
{
	ll R=1;
	while(P>0)
	{
		if(P%2==1)
		{
			R=(R*B)%MOD;
		}
		P/=2;
		B=(B*B)%MOD;
	}
	return R;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T,p=0;
    fact[0]=1;
    for(ll i=1;i<=1000000;i++)
    {
        fact[i]=(i*fact[i-1])%MOD;
    }
    cin >> T;
    while(T--)
    {
        ll n,r,a,b;
        cin >> n >> r;
        a=fact[n]%MOD;
        b=(fact[n-r]*fact[r])%MOD;
        cout << "Case " << ++p << ": " << (a*bmod(b,MOD-2))%MOD << endl;
    }
}
/*According to euler's theorem a^-1 is equvalent to (a^m-2 mod m)*/
