ll n,a[100],dp[100];

ll kadane()
{
    dp[0]=a[0];
    ll mx = a[0];
    repl(i,1,n-1)
    {
        dp[i] = max(a[i],dp[i-1]+a[i]);
        mx = max(mx,dp[i]);
    }
    return mx;
}

int main()
{
    Fast
    cin >> n;
    FLR(i,n) cin >> a[i];
    cout << kadane() << "\n";
}
/*
5
1 -3 2 1 -1
*/
