//https://www.spoj.com/problems/DQUERY/vn/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/* msi1427 */

#define ll           long long
#define ull          long long unsigned
#define LD           long double
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(ll i=0;i<n;i++)
#define RFOR(i,n)   for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(ll i=n-1;i>=0;i--)
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(ll i=a;i<=b;i++)
#define casep(z)     cout << "Case " << z << ": ";
#define Fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(a)        a.size()
#define all(x)       x.begin(),x.end()
#define SORT(a,n)    sort(a,a+n)
#define RSORT(a,n)   sort(a,a+n,greater<ll>())
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define VSORT(v)     sort(all(v))
#define VRSORT(v)    sort(all(v),greater<ll>())
#define pb           push_back
#define pf            push_front
#define pob          pop_back()
#define pof          pop_front()
#define ff           first
#define ss           second
#define tt           true
#define fs           false
#define MP           make_pair
#define MEM(x,n)      memset((x),n,sizeof(x))
#define bsrch(a,n,x) binary_search(a,a+n,x)
#define vi           vector<int>
#define vll          vector<ll>
#define PI          acos(-1.0)
#define LB(a,x)      (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x)      (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define PQ           priority_queue
#define heap       PQ< ll , vll , greater < ll > >
#define REV(x)       reverse(all(x))
#define mpii         map<int,int>
#define mpll         map<ll,ll>
#define cig          cin.ignore()
#define INF          (ll)1e10
#define EPS          1e-9
#define prec(n)      fixed << setprecision(n)
#define lb           lower_bound
#define ub           upper_bound
#define fin          freopen("in.txt","r",stdin)
#define fout         freopen("out.txt","w",stdout)
#define sc           scanf
#define pt           printf
#define np           next_permutation
#define IT(it,x)     for(it=x.begin();it!=x.end();it++)
#define sci(x)       scanf("%d",&x);
#define scl(x)       scanf("%lld",&x);
#define scd(x)       scanf("%lf",&x);

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))

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

#define MOD 1000000007
#define MAX 1000005

#define N 200000

ll ara[N+5];
ll oc[1000005];

struct data
{
    ll l,r,id;
};

data Q[N+5];
ll answer[N+5];
ll sq;

bool cmp(data A,data B)
{
    if(A.l/sq!=B.l/sq)return A.l/sq < B.l/sq;
    return A.r<B.r;
}

ll value;

ll add(ll pos)
{
    ll X = ++oc[ara[pos]];
    if(X==1) value++;
}

ll remove(ll pos)
{
    ll X = --oc[ara[pos]];
    if(X==0) value--;

}

int main()
{
    ll n;
    ll q;
    scanf("%lld",&n);
    sq = sqrt(n);
    for(ll i = 0;i<n;i++)scanf("%lld",&ara[i]);
    scanf("%lld",&q);
    for(ll i = 0;i<q;i++){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        Q[i].l=l-1;
        Q[i].r=r-1;
        Q[i].id=i;
    }
    sort(Q,Q+q,cmp);
    ll mol = 0;
    ll mor = -1;
    for(ll i = 0;i<q;i++){
        ll l = Q[i].l;
        ll r = Q[i].r;
        while(mor < r){
            mor++;
            add(mor);
        }
        while(mor > r){
            remove(mor);
            mor--;
        }
        while(mol < l){
            remove(mol);
            mol++;
        }
        while(mol>l){
            mol--;
            add(mol);
        }
        answer[Q[i].id]=value;
    }
    for(ll i = 0;i<q;i++){
        printf("%lld\n",answer[i]);
    }

}
