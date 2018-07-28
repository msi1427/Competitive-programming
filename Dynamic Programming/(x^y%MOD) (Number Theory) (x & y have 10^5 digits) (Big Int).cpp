
ll BMod(ll B,string P,ll M)
{
    ll R=1;
    for(ll i=sz(P)-1;i>=0;i--)
    {
        if(P[i]=='1') R=(R*B)%M;
        B=(B*B)%M;
    }
    return R;
}

#define MOD 1000000007

ll T;
string x,y;

string binrep(string n)
{
    string div,ex;
    while(n!="")
    {
        ll c=0;
        div.clear();
        bool xx = false;
        FLR(i,sz(n))
        {
            c=c*10+(n[i]-'0');
            if(c/2 && !xx) xx = true;
            if(xx) div.pb((c/2)+'0');
            c=c%2;
        }
        ex.pb(c+'0');
        n = div;
    }
    REV(ex);
    return ex;
}

int main()
{
    Fast
    cin >> T;
    while(T--)
    {
        cin >> x >> y;
        ll c = 0;
        FLR(i,sz(x))
        {
            c = c*10 + (x[i]-'0');
            c = c%MOD;
        }
        string p = binrep(y);
        cout << BMod(c,p,MOD) << "\n";
    }
}
