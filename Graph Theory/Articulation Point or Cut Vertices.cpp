#define MOD 1000000007
#define MAX 1000005

bool vis[MAX],AP[MAX];
vector<ll>ad[MAX];
ll low[MAX],disc[MAX],pr[MAX];
ll n,m,u,v,T,tim;

void dfs(ll xx)
{
    vis[xx]=true;
    low[xx]=disc[xx]= ++tim;
    ll ch=0;
    FLR(i,sz(ad[xx])){
        ll yy = ad[xx][i];
        if(!vis[yy]){
            ch++;
            pr[yy]=xx;
            dfs(yy);
            low[xx]=min(low[xx],low[yy]);
            if(pr[xx]!=-1 && low[yy]>=disc[xx]) AP[xx]=true;
            if(pr[xx]==-1 && ch>1) AP[xx]=true;
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
    MEM(AP,false);
    FLR(i,MAX) ad[i].clear();
    MEM(low,0);
    MEM(disc,0);
    MEM(pr,-1);
    tim=0;
    cin>>n>>m;
    FLR(i,m){
    cin>>u>>v;
    ad[u].pb(v);
    ad[v].pb(u);
    }
    dfs(1);
    repl(i,1,n){
    if(AP[i]) cout << i << "\n";
    }
    }
}
/*
1
7 8
1 2
1 3
2 4
3 4
4 5
5 7
6 7
4 6
*/
