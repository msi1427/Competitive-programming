ll T,n,m,d[100005];

struct edge
{
    ll u,v,w;
};

int main()
{
    Fast
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        ms(d,INF);
        struct edge s[n+9];
        FLR(i,m) cin >> s[i].v >> s[i].u >> s[i].w;
        d[0]=0;
        FLR(i,n)
        {
            FLR(j,m)
            {
                if(d[s[j].u]+s[j].w<d[s[j].v]) d[s[j].v] = d[s[j].u]+s[j].w;
            }
        }
    }
}
