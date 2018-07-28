ll T,n,pr[20][20];
ll dp[17][1<<17];

bool check(ll n,ll pos) {return (n&(1<<pos));}
ll SET(ll n,ll pos){return (n|(1<<pos));}
ll RESET(ll n,ll pos) {return(n&~(1<<pos));}

ll call(ll xx,ll mask)
{
    ll sum;
    sum=-1;
    if(xx==n) return 0;
    if(dp[xx][mask]==-1)
    {
        FLR(i,n)
        {
            if(check(mask,i)==0)
            {
                sum=max(sum,pr[xx][i]+call(xx+1,SET(mask,i)));
            }
        }
        dp[xx][mask]=sum;
        return sum;
    }
    else return dp[xx][mask];
}

int main()
{
    Fast
    scanf("%lld",&T);
    repl(tc,1,T)
    {
        scanf("%lld",&n);
        FLR(i,n) FLR(j,n) scanf("%lld",&pr[i][j]);
        MEM(dp,-1);
        printf("Case %lld: %lld\n",tc,call(0,0));
    }
}
