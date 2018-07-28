
//LOJ 1030

ll T,n;
double g[212],dp[212];

double expected_value()
{
    dp[n]=g[n];
    for(ll i=n-1;i>=1;i--)
    {
        ll cc=0;
        for(ll j=i+1,k=0;k<6;j++,k++)
        {
            if(j>n) cc++;
            else dp[i]+=(dp[j]+g[i]);
        }
        if(cc)
        {
            cc=6-cc;
            dp[i]/=(double)cc;
        }
        else dp[i]/=6.0;
    }
    return dp[1];
}

int main()
{
    Fast
    cin>>T;
    repl(tc,1,T)
    {
        FLR(i,212) g[i]=0.0;
        FLR(i,212) dp[i]=0.0;
        cin>>n;
        repl(i,1,n) cin>>g[i];
        cout << "Case " << tc << ": " << prec(10) << expected_value() << "\n";
    }
}
