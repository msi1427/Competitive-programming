#define MAX 6006

ll T,n,m,u,v,w,cnt;
vector< pair<ll,pll> >ad;
ll pr[212];

ll FIND(ll r)
{
    return (pr[r]==r)?r:pr[r]=FIND(pr[r]);
}

ll krushkal()
{
    sort(all(ad));
    FLR(i,212) pr[i]=i;
    ll sum=0,cnt=0,id=-1;
    FLR(i,sz(ad))
    {
        ll xx=ad[i].ss.ff;
        ll yy=ad[i].ss.ss;
        ll zz=ad[i].ff;
        if(FIND(xx)!=FIND(yy))
        {
            pr[FIND(xx)]=FIND(yy);
            cnt++;
            sum+=zz;
        }
        else id=i;
    }
    if(id!=-1) ad.erase(ad.begin()+id);
    return (cnt==n-1)?sum:-1;
}

int main()
{
    scanf("%lld",&T);
    repl(tc,1,T)
    {
        ad.clear();
        printf("Case %lld:\n",tc);
        scanf("%lld %lld",&n,&m);
        FLR(i,m)
        {
            cnt=0;
            scanf("%lld %lld %lld",&u,&v,&w);
            ad.pb(MP(w,MP(min(u,v),max(u,v))));
            if(i<n-1)
            {
                printf("-1\n");
                continue;
            }
            cout << krushkal() << "\n";
        }
    }
}
