ll m,n;
ll coins[100];

ll nofways(ll m,ll n)
{
    ll T[n+1][m+1];
    FLR(i,m) T[0][i]=1;
    repl(i,1,n+1)
    {
        FLR(j,m)
        {
            ll x = (i-coins[j] >= 0)?T[i-coins[j]][j]:0;
            ll y = (j>=1)?T[i][j-1]:0;
            T[i][j] = x+y;
        }
    }
    return T[n][m-1];
}

int main()
{
    Fast
    cin >> m;
    FLR(i,m) cin >> coins[i];
    cin >> n;
    cout << nofways(m,n) << "\n";
}
