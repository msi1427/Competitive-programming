ll T[1000],x,n;
ll R[1000];
vector<ll>coins;

void mincoin()
{
    ms(T,INF);
    ms(R,-1);
    T[0]=0;
    repl(j,0,sz(coins))
    {
        repl(i,1,x)
        {
            if(i>=coins[j])
            {
                if(T[i]>T[i-coins[j]]+1)
                {
                    T[i]=T[i-coins[j]]+1;
                    R[i]=j;
                }
            }
        }
    }
    cout << T[x] << "\n";
    if(R[x]==-1) cout << "NONE\n";
    else
    {
        ll xx = x;
        while(xx!=0)
        {
            ll j = R[xx];
            cout << coins[j] << " ";
            xx-=coins[j];
        }
        cout << "\n";
    }
    return;
}

int main()
{
    Fast
    cin >> n;
    FLR(i,n)
    {
        cin >> x;
        coins.pb(x);
    }
    cin >> x;
    mincoin();
}

/*
4
7 2 3 6
9
*/
