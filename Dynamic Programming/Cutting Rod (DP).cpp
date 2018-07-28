ll n,cost[100],dp[100];

ll getrod()
{
    repl(i,1,n)
    {
        ll mx = -INF;
        FLR(j,i) mx = max(mx,cost[j]+dp[i-j-1]);
        dp[i]=mx;
    }
    return dp[n];
}

int main()
{
    Fast
    cin >> n;
    FLR(i,n) cin >> cost[i];
    cout << getrod() << "\n";
}
