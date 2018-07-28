
ll T,n,dp[105];
vector< pair<double,double> >v(105);

int main()
{
    Fast
    cin >> T;
    while(T--)
    {
        ms(dp,0);
        cin >> n;
        repl(i,1,n) cin >> v[i].ff >> v[i].ss;
        v[0].ff = -INF;
        v[0].ss = INF;
        repl(i,1,n)
        {
            FLR(j,i)
            {
                if(v[i].ff>v[j].ff && v[i].ss<v[j].ss)
                    dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        ll mx = -INF;
        repl(i,1,n) mx = max(mx,dp[i]);
        cout << mx << "\n";
    }
}
