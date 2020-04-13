// https://cp-algorithms.com/algebra/fft.html
// https://toph.co/p/play-the-lottery

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/* msi1427 */

#define ll           long long
#define ull          long long unsigned
#define LD           long double
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(ll i=0;i<n;i++)
#define RFOR(i,n)    for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(ll i=n-1;i>=0;i--)
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(ll i=a;i<=b;i++)
#define casep(z)     cout << "Case " << z << ": ";
#define Fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(a)        a.size()
#define all(x)       x.begin(),x.end()
#define SORT(a,n)    sort(a,a+n)
#define RSORT(a,n)   sort(a,a+n,greater<ll>())
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define tll          tuple<ll,ll,ll>
#define VSORT(v)     sort(all(v))
#define VRSORT(v)    sort(v.rbegin(),v.rend())
#define pb           push_back
#define eb           emplace_back
#define pf           push_front
#define pob          pop_back()
#define pof          pop_front()
#define ff           first
#define ss           second
#define tt           true
#define fs           false
#define MP           make_pair
#define MEM(x,n)     memset((x),n,sizeof(x))
#define bsrch(a,n,x) binary_search(a,a+n,x)
#define vi           vector<int>
#define vll          vector<ll>
#define PI           acos(-1.0)
#define LB(a,x)      (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x)      (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define PQ           priority_queue
#define heap         PQ< ll , vector<ll> , greater < ll > >
#define REV(x)       reverse(all(x))
#define mpii         map<int,int>
#define mpll         map<ll,ll>
#define cig          cin.ignore()
#define INF          (ll)1e18
#define EPS          1e-9
#define prec(n)      fixed << setprecision(n)
#define lb           lower_bound
#define ub           upper_bound
#define fin          freopen("in.txt","r",stdin)
#define fout         freopen("out.txt","w",stdout)
#define sc           scanf
#define pt           printf
#define np           next_permutation
#define IT(it,x)     for(auto it=x.begin();it!=x.end();it++)
#define sci(x)       scanf("%d",&x);
#define scl(x)       scanf("%lld",&x);
#define scd(x)       scanf("%lf",&x);
#define scs(x)       scanf("%s",x);

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define EulerGamma      0.57721566490153286060651209

typedef
tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

ll ceiling(ll x,ll y)
{
    if(x%y) return ((x/y)+1);
    else return (x/y);
}

ll gcd(ll x,ll y)
{
    return ((y==0)?x:gcd(y,x%y));
}

ll lcm(ll x,ll y)
{
    return ((x*y)/gcd(x,y));
}

ll BMod(ll B,ll P,ll M)
{
    ll R=1;
    B=B%M;
    while(P)
    {
        if(P&1)
            R=(R*B)%M;
        P >>= 1;
        B=(B*B)%M;
    }
    return R;
}

bool check(ll n,ll pos) {return (n&(1<<pos));}
ll SET(ll n,ll pos){return (n|(1<<pos));}
ll RESET(ll n,ll pos) {return(n&~(1<<pos));}
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

#define MOD 786433
#define MAX 1000005


ll primitive_root(ll p){
    vector<ll>factor;
    ll phi = p-1;
    ll n = phi;

    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            factor.eb(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) factor.eb(n);

    for(ll res=2;res<=p;res++){
        bool ok=true;
        for(ll i=0;i<factor.size();i++){
            ok &= (BMod(res,phi/factor[i],MOD)!=1);
        }
        if(ok) return res;
    }
    return -1;
}

ll g,inv_n,w[MAX],rev[MAX];

void precal(ll n){
    ll sz = abs(31 - __builtin_clz(n));
    ll r = BMod(g,(MOD-1)/n,MOD);
    inv_n = BMod(n,MOD-2,MOD);
    w[0]=w[n]=1;
    for(ll i=1;i<n;i++) w[i]=(w[i-1]*r)%MOD;
    for(ll i=1;i<n;i++) rev[i]=(rev[i >> 1] >> 1) | ((i&1) << (sz-1));
    return;
}


void NTT(vector<ll>& a, bool invert){
    ll n = a.size();
    for(ll i=1;i<n-1;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);

    for(ll m=2; m<=n; m <<= 1){
        for(ll i=0; i<n; i+=m){
            for(ll j=0; j<(m>>1); j++){
                ll &u=a[i+j],&v=a[i+j+(m>>1)];
                ll t=v*w[invert ? n-n/m*j:n/m*j]%MOD;
                v=u-t<0?u-t+MOD:u-t;
                u=u+t>=MOD?u+t-MOD:u+t;
            }
        }
    }
    if(invert) for(ll i=0; i<n; i++) a[i] = (a[i]*inv_n)%MOD;
    return;
}

vector<ll> Mul(vector<ll>a,vector<ll>b){
    vector<ll> fa(a.begin(),a.end());
    vector<ll> fb(b.begin(),b.end());
    ll sz=1;
    while(sz< max((ll)a.size(),(ll)b.size())) sz <<= 1;
    sz <<= 1;
    precal(sz);
    fa.resize(sz);
    fb.resize(sz);

    NTT(fa,false);
    NTT(fb,false);
    for(ll i=0;i<sz;i++) fa[i]=(fa[i]*fb[i])%MOD;
    NTT(fa,true);
    vector<ll>res(fa.begin(),fa.end());
    while(res.size() && res.back()==0) res.pop_back();
    return res;
}

vector<ll>box[MAX];

vector<ll> call(ll l,ll r){
    if(l==r) return box[l];
    ll m = (l+r)/2;
    return Mul(call(l,m),call(m+1,r));
}

ll m,x;

int main()
{
    Fast
    cin>>m;
    repl(i,1,m) {
        cin>>x;
        ll mx = 0;
        vector<pll>v(x);
        FLR(j,x){
            cin>>v[j].ff>>v[j].ss;
            mx = max(mx,v[j].ff);
        }
        box[i].resize(mx+1);
        FLR(j,x) box[i][v[j].ff]=v[j].ss;
    }
    g = primitive_root(MOD);
    vector<ll>ans = call(1,m);
    FLR(i,ans.size()) if(ans[i]) cout << i << " " << ans[i] << "\n";
}
/*

*/
