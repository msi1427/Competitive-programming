vector<ll>v;
ll s,n,x;
bool dp[100][100];

bool issubsetsum(ll n,ll s)
{
    FLR(i,n) dp[i][0]=true;
    repl(i,1,n)
    {
        repl(j,1,s)
        {
            if(j<v[i-1])
                dp[i][j]=dp[i-1][j];
            if(j>=v[i-1])
                dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];
        }
    }
    return dp[n][s];
}
int main()
{
    Fast
    cin >> n;
    FLR(i,n)
    {
        cin >> x;
        v.pb(x);
    }
    cin >> s;
    if(issubsetsum(sz(v),s)) cout << "FOUND\n";
    else  cout << "NOT FOUND\n";
}

