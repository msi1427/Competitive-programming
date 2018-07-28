ll n,t,a[30],mx,ac[30],b[30];
void rec(int xx)
{
    if(xx==t)
    {
        ll cc=0;
        FLR(i,t) if(b[i]) cc+=a[i];
        if(cc<=n)
        {
            if(cc>mx)
            {
                mx = max(mx,cc);
                FLR(i,t) ac[i]=b[i];
            }
        }
        return;
    }
    b[xx]=1;
    rec(xx+1);
    b[xx]=0;
    rec(xx+1);
    return;
}
int main()
{
    Fast
    while(cin>>n>>t)
    {
        FLR(i,t) cin>>a[i];
        mx=0;
        ms(ac,0);
        ms(b,0);
        rec(0);
        FLR(i,t) if(ac[i]) cout << a[i] << " ";
        cout << "sum:" << mx << endl;
    }
}
