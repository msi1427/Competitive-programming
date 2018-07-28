//LOJ 1068

ll T,k,dp[10][2][100][100];
string a,b;

ll call(ll idx,ll tight,ll cur,string s,ll sum)
{
    if(idx>=sz(s))
    {
        if(cur%k==0 && sum%k==0) return 1;
        else return 0;
    }
    if(dp[idx][tight][cur][sum]!=-1) {
        return dp[idx][tight][cur][sum];
    }
    if(tight)
    {
        ll cc=0;
        ll limit=s[idx]-'0';
        repl(i,0,limit)
        {
            ll xx = cur*10+i;
            ll yy = sum+i;
            if(i==limit) cc+=call(idx+1,1,xx%k,s,yy);
            else cc+=call(idx+1,0,xx%k,s,yy);
        }
        dp[idx][tight][cur][sum]=cc;
        return cc;
    }
    else
    {
        ll cc=0;
        repl(i,0,9)
        {
            ll xx = cur*10+i;
            ll yy = sum+i;
            cc+=call(idx+1,0,xx%k,s,yy);
        }
        dp[idx][tight][cur][sum]=cc;
        return cc;
    }
}

int main()
{
    Fast
    cin>>T;
    repl(tc,1,T)
    {
        a.clear();
        b.clear();
        cin>>a>>b>>k;
        cout<<"Case "<<tc<<": ";
        if(k>=100) cout << "0\n";
        else
        {
            MEM(dp,-1);
            ll l=call(0,1,0,a,0);
            MEM(dp,-1);
            ll r=call(0,1,0,b,0);
            ll xx=0,yy=0;
            FLR(i,sz(a))
            {
                ll qq = (ll)(a[i]-'0');
                xx=xx*10+qq;
                yy+=qq;
            }
            if(xx%k==0 && yy%k==0) l--;
            cout << r-l << "\n";
        }
    }
}
