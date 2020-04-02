/*
WHITE : Vertex is not processed yet.  Initially
        all vertices are WHITE.

GRAY : Vertex is being processed (DFS for this 
       vertex has started, but not finished which means
       that all descendants (ind DFS tree) of this vertex
       are not processed yet (or this vertex is in function
       call stack)

BLACK : Vertex and all its descendants are 
        processed.

While doing DFS, if we encounter an edge from current 
vertex to a GRAY vertex, then this edge is back edge 
and hence there is a cycle.
*/

#define MAX 1000005

ll n,m,u,v,cycle,col[MAX];
vector<ll>ad[MAX];

void dfs(ll node){
    if(col[node]==2) return;
    if(col[node]==1) {
        cycle++;
        return;
    }
    col[node]=1;
    for(auto xx: ad[node]) dfs(xx);
    col[node]=2;
    return;
}

int main()
{
    Fast
    cin>>n>>m;
    FLR(i,m) {
        cin>>u>>v;
        ad[u].pb(v);
    }
    dfs(1);
    cout << cycle << "\n";
}
/*
5 8
1 2
2 2
2 3
3 3
3 4
4 2
4 5
5 5
*/
