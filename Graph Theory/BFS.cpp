ll T,N,R,u,v,p,d1[105],d2[105],x,y;
vector<ll>ad[105];

void bfs1(ll s)
{
    queue<ll>q;
    q.push(s);
    d1[s]=0;
    while(!q.empty())
    {
        ll r = q.front();
        q.pop();
        FLR(i,sz(ad[r]))
        {
            if(d1[ad[r][i]]==-1)
            {
                d1[ad[r][i]]=d1[r]+1;
                q.push(ad[r][i]);
            }
        }
    }
}

void bfs2(ll s)
{
    queue<ll>q;
    q.push(s);
    d2[s]=0;
    while(!q.empty())
    {
        ll r = q.front();
        q.pop();
        FLR(i,sz(ad[r]))
        {
            if(d2[ad[r][i]]==-1)
            {
                d2[ad[r][i]]=d2[r]+1;
                q.push(ad[r][i]);
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
        FLR(i,105) ad[i].clear();
        ms(d1,-1);
        ms(d2,-1);
        scanf("%lld %lld",&N,&R);
        FLR(i,R)
        {
            scanf("%lld %lld",&u,&v);
            ad[u].pb(v);
            ad[v].pb(u);
        }
        scanf("%lld %lld",&x,&y);
        bfs1(x);
        bfs2(y);
        ll mx=-1;
        FLR(i,N) mx=max(mx,d1[i]+d2[i]);
        printf("Case %lld: %lld\n",++p,mx);
    }
}
