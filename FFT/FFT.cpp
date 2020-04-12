//UVA 12879 - Golf Bot

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

#define MOD 1000000007
#define MAX 1000005

void fft(vector< complex<double> >& a, bool invert){
    int n = a.size();
    for(int i=1,j=0; i<n; i++){
        int bit;
        for(bit=n>>1; j>=bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2; len<=n; len <<= 1){
        double angle = 2.0*PI/len*(invert?-1:1);
        complex<double> wlen(cos(angle),sin(angle));
        for(int i=0; i<n; i+=len){
            complex<double> w(1);
            for(int j=0; j<len/2; j++){
                complex<double> u = a[i+j];
                complex<double> v = a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w *= wlen;
            }
        }
    }
    if(invert) for(int i=0; i<n; i++) a[i]/=n;
    return;
}

vector<ll> Mul(vector<ll>& a,vector<ll>& b){
    vector< complex<double> > fa(a.begin(),a.end());
    vector< complex<double> > fb(b.begin(),b.end());
    int n=1;
    while(n< max(a.size(),b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa,false);
    fft(fb,false);
    for(int i=0; i<n; i++) fa[i]*=fb[i];
    fft(fa,true);

    vector<ll>res(n);
    for(int i=0;i<n;i++) res[i]=round(fa[i].real());

    return res;
}

ll n,m,s,h;

int main()
{
    Fast
    while(cin>>n){
        vector<ll>shot(200001);
        shot[0]=1;
        FLR(i,n) {cin>>s; shot[s]=1; }
        vector<ll>reach = Mul(shot,shot);
        ll ans = 0;
        cin>>m;
        FLR(i,m) {cin>>h; if(reach[h])ans++; }
        cout << ans << "\n";
    }
}
/*
3
1
3
5
6
2
4
5
7
8
9
*/
