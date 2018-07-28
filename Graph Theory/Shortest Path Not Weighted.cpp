ll T,n,p;
char s[15][15];
ll d[15][15];
bool vis[15][15];

ll bfs(ll sx, ll sy, ll ex, ll ey)
{
    ms(d,-1);
    queue<pll>q;
    q.push(MP(sx,sy));
    d[sx][sy]=0;
    while(!q.empty())
    {
        ll x = q.front().ff;
        ll y = q.front().ss;
        q.pop();
        FLR(i,4)
        {
            ll xx = x + dx[i];
            ll yy = y + dy[i];
            if(xx>=0 && yy>=0 && xx<n && yy<n && (s[xx][yy]=='.' || vis[xx][yy] || (xx==ex &&yy==ey)) && (d[xx][yy]==-1))
            {
                d[xx][yy]=d[x][y]+1;
                q.push(MP(xx,yy));
            }
        }
    }
    return d[ex][ey];
}

int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        map<char,pll>mp;
        scanf("%lld",&n);
        FLR(i,n) scanf("%s",s[i]);
        FLR(i,n) FLR(j,n) if(isalpha(s[i][j])) mp[s[i][j]]=MP(i,j);
        map<char,pll>::iterator it,it1;
        it1 = mp.end();
        it1--;
        ll cc=0;
        ms(vis,false);
        IT(it,mp)
        {
            ll x = (it->ss).ff;
            ll y = (it->ss).ss;
            if(it!=it1)
            {
                it++;
                ll a = (it->ss).ff;
                ll b = (it->ss).ss;
                ll yy = bfs(x,y,a,b);
                if(yy==-1)
                {
                    cc=-1;
                    break;
                }
                else
                {
                    cc+=yy;
                    vis[x][y]=true;
                    vis[a][b]=true;
                }
//                cout << x << " " << y << " " << a << " " << b << " " << cc << endl;
                it--;
            }
        }
        if(cc!=-1) printf("Case %lld: %lld\n",++p,cc);
        else printf("Case %lld: Impossible\n",++p);
    }
}
