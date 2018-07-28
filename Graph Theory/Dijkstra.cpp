vector<pll>ad[30005];
ll d[30005],d1[30005],d2[30005];
ll T,n,p;

ll DJ(ll src)
{
    ll mx=-INF;
    FLR(i,30005) d[i]=INF;
    heap pq;
    pq.push(MP(0,src));
    d[src] = 0;
    while(! pq.empty())
    {
        int u = pq.top().ss;
        pq.pop();
        FLR(i,sz(ad[u]))
        {
            ll v = ad[u][i].ff;
            ll w = ad[u][i].ss;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(MP(d[v],v));
            }
        }
    }
    ll node;
    FLR(i,n)
    {
        if(mx<=d[i])
        {
            mx=d[i];
            node=i;
        }
    }
    return node;
}

void DJ1(ll src)
{
    FLR(i,30005) d1[i]=INF;
    heap pq;
    pq.push(MP(0,src));
    d1[src] = 0;
    while(! pq.empty())
    {
        int u = pq.top().ss;
        pq.pop();
        FLR(i,sz(ad[u]))
        {
            ll v = ad[u][i].ff;
            ll w = ad[u][i].ss;
            if(d1[v]>d1[u]+w)
            {
                d1[v]=d1[u]+w;
                pq.push(MP(d1[v],v));
            }
        }
    }
}

void DJ2(ll src)
{
    FLR(i,30005) d2[i]=INF;
    heap pq;
    pq.push(MP(0,src));
    d2[src] = 0;
    while(! pq.empty())
    {
        int u = pq.top().ss;
        pq.pop();
        FLR(i,sz(ad[u]))
        {
            ll v = ad[u][i].ff;
            ll w = ad[u][i].ss;
            if(d2[v]>d2[u]+w)
            {
                d2[v]=d2[u]+w;
                pq.push(MP(d2[v],v));
            }
        }
    }
}

int main()
{
    //Fast
    scanf("%lld",&T);
    while(T--)
    {
        ll u,v,w;
        scanf("%lld",&n);
        FLR(i,30005) ad[i].clear();
        FLR(i,n-1)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            ad[u].pb(MP(v,w));
            ad[v].pb(MP(u,w));
        }
        printf("Case %d:\n",++p);
        ll x=DJ(0);
        ll y=DJ(x);
        DJ1(x);
        DJ2(y);
        FLR(i,n) cout << max(d1[i],d2[i]) << "\n";
    }
}
