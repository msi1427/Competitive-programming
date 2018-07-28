//COIN CHANGE DP :  (LOJ 1231 & 1232)
//Recursive
#define MOD 100000007
#define MAX 1000005

ll n,k,T;
ll coins[100],times[100],dp[100][1005];

ll call(ll pos,ll val)
{
    if(val==0) return 1;
    if(val<0 || pos==n) return 0;
    if(dp[pos][val]!=-1) return dp[pos][val];
    ll cc=0;
    for(ll i=0;i<=times[pos];i++) cc+=call(pos+1,val-i*coins[pos])%MOD;
    dp[pos][val]=cc%MOD;
    return dp[pos][val];
}

int main()
{
    Fast
    cin>>T;
    repl(tc,1,T){
    MEM(dp,-1);
    cin >> n >> k;
    FLR(i,n) cin >> coins[i];
    FLR(i,n) cin >> times[i];
    cout<<"Case "<<tc<<": "<< call(0,k) << "\n";
    }
}
//Iterative:
#define MOD 100000007
#define MAX 1000005

ll T,n,k,coins[212],dp[10005];

int main()
{
    Fast
    fout;
    cin>>T;
    repl(tc,1,T)
    {
        MEM(dp,0);
        cin>>n>>k;
        FLR(i,n) cin>>coins[i];
        dp[0]=1;
        FLR(i,n) repl(j,1,k) if(coins[i]<=j) dp[j]+=dp[j-coins[i]]%MOD;
        cout << "Case " << tc << ": " << dp[k]%MOD << "\n";
    }
}
