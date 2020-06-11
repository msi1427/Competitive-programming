// PSEGTREE - Make Versions in Segment Tree

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

struct node{
    ll val;
    ll l,r;
    node(ll l=0, ll r=0, ll val=0) : l(l), r(r), val(val){}
};

node tr[30*MAX];
ll root[MAX];
ll cursz;
ll n,q,a[MAX];

inline ll update(ll &now,ll L,ll R,ll idx,ll val){
    if(L>idx || R<idx) return now;
    if(L==R){
        cursz++;
        tr[cursz]=tr[now];
        tr[cursz].val+=val;
        return cursz;
    }
    ll m = (L+R)>>1;
    ll ret = ++cursz;
    if(idx<=m){
        if(!tr[now].l) tr[now].l = ++cursz;
        tr[ret].l = update(tr[now].l,L,m,idx,val);
        tr[ret].r = tr[now].r;
    }
    else {
        if(!tr[now].r) tr[now].r = ++cursz;
        tr[ret].r = update(tr[now].r,m+1,R,idx,val);
        tr[ret].l = tr[now].l;
    }

    tr[ret].val=tr[ tr[ret].l ].val+tr[ tr[ret].r ].val;
    return ret;
}

inline ll query(ll &now,ll L,ll R,ll i,ll j){
    if(L>j || R<i) return 0;
    if(L>=i && R<=j) return tr[now].val;
    ll m = (L+R)>>1;
    ll p1 = query(tr[now].l,L,m,i,j);
    ll p2 = query(tr[now].r,m+1,R,i,j);
    return p1+p2;
}


int main()
{
    Fast
    root[0]=0;
    cin>>n;
    repl(i,1,n) {
        cin>>a[i];
        root[i]=update(root[i-1],1,n,i,a[i]);
    }
    cin>>q;
    ll cnt = 1;
    while(q--){
        ll com,idx,pos,val,l,r;
        cin>>com;
        if(com==1){
            cin>>idx>>pos>>val;
            root[n + cnt++]=update(root[n+idx],1,n,pos,val);
        }
        else {
            cin>>idx>>l>>r;
            cout << query(root[n+idx],1,n,l,r) << "\n";
        }
    }
}
/*
*/
