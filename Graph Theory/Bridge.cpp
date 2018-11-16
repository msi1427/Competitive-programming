#define MOD 1000000007
#define MAX 1000005

/*
The idea is similar to O(V+E) algorithm for Articulation Points. We do DFS traversal of the given graph.
In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative
to reach u or an ancestor of u from subtree rooted with v. As discussed in the previous post, the value low[v] indicates
earliest visited vertex reachable from subtree rooted with v. The condition for an edge (u, v) to be a bridge is, “low[v] > disc[u]”.
*/

bool vis[MAX];
vector<ll>ad[MAX];
vector<pll>brid;
ll low[MAX],disc[MAX],pr[MAX];
ll n,m,u,v,T,tim;

void dfs(ll xx)
{
    vis[xx]=true;
    low[xx]=disc[xx]= ++tim;
    FLR(i,sz(ad[xx])){
        ll yy = ad[xx][i];
        if(!vis[yy]){
            pr[yy]=xx;
            dfs(yy);
            low[xx]=min(low[xx],low[yy]);
            if(low[yy]>disc[xx]) brid.pb(MP(xx,yy));
        }
        else if(yy!=pr[xx]) low[xx]=min(low[xx],disc[yy]);
    }
    return;
}

int main()
{
    Fast
    cin>>T;
    while(T--){
    MEM(vis,false);
    FLR(i,MAX) ad[i].clear();
    MEM(low,0);
    MEM(disc,0);
    MEM(pr,-1);
    brid.clear();
    tim=0;
    cin>>n>>m;
    FLR(i,m){
    cin>>u>>v;
    ad[u].pb(v);
    ad[v].pb(u);
    }
    dfs(1);
    FLR(i,sz(brid)) cout << brid[i].ff << " " << brid[i].ss << '\n';
    }
}
/*
1
7 8
1 2
1 3
3 4
4 5
5 7
6 7
4 6
2 4
*/
