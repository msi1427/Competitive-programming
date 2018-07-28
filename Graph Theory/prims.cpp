#define MAX 10005
bool marked[MAX];
vector <pll> adj[MAX];

ll prim(ll x)
{
    priority_queue<pll, vector<pll>, greater<pll> > Q;
    ll y;
    ll minimumCost = 0;
    pll p;
    Q.push(MP(0, x));
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.ss;
        if(marked[x] == true)
            continue;
        minimumCost += p.ff;
        marked[x] = true;
        for(ll i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].ss;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    ll nodes, edges, x, y, T;
    ll weight=1, minimumCost;
    cin >> T;
    while(T--)
    {
        ms(marked,false);
        FLR(i,MAX) adj[i].clear();
        cin >> nodes >> edges;
        for(ll i = 0; i < edges; ++i)
        {
            cin >> x >> y;
            adj[x].pb(MP(weight, y));
            adj[y].pb(MP(weight, x));
        }
        minimumCost = prim(1);
        cout << minimumCost << endl;
    }
    return 0;
}
