ll T,n,u,v,s,d,vis[50005],next[50005],p;
vector<ll>ad[50005],path;

void bfs(ll s,ll d)
{
    queue<ll>q;
    ms(vis,0);
    ms(next,-1);
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        ll xx = q.front();
        q.pop();
        FLR(i,sz(ad[xx]))
        {
            ll yy = ad[xx][i];
            if(!vis[yy])
            {
                vis[yy]=1;
                next[yy]=xx;
                q.push(yy);
            }
        }
    }
    path.pb(d);
    while(next[d]!=-1)
    {
        d=next[d];
        path.pb(d);
    }
    REV(path);
}

int main()
{
    //Fast
    scanf("%lld",&T);
    while(T--)
    {
        FLR(i,50005) ad[i].clear();
        path.clear();
        scanf("%lld",&n);
        FLR(i,n)
        {
            ll xx;
            scanf("%lld",&xx);
            if(!i)
            {
                d=xx;
                s=xx;
                continue;
            }
            ad[xx].pb(d);
            ad[d].pb(xx);
            d=xx;
        }
        FLR(i,50005) if(sz(ad[i])) VSORT(ad[i]);
        bfs(s,d);
        printf("Case %lld:\n",++p);
        FLR(i,sz(path))
        {
            printf("%lld",path[i]);
            if(i<sz(path)-1) printf(" ");
        }
        printf("\n");
    }
}
