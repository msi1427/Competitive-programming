ll u,v,p,ad[105][105];
void FW()
{
    FLR(k,105) FLR(i,105) FLR(j,105) ad[i][j]=min(ad[i][j],ad[i][k]+ad[k][j]);
}

int main()
{
    Fast
    while(cin>>u>>v &&(u||v))
    {
        set<ll>st;
        FLR(i,105) FLR(j,105) ad[i][j]=INF;
        FLR(i,105) ad[i][i]=0;
        ad[u-1][v-1]=1;
        st.insert(u);
        st.insert(v);
        while(cin>>u>>v && (u||v))
        {
            ad[u-1][v-1]=1;
            st.insert(u);
            st.insert(v);
        }
        FW();
        ll cc=0;
        FLR(i,105) FLR(j,105) if(i!=j && ad[i][j]!=INF) cc+=ad[i][j];
        cout << "Case " << ++p << ": average length between pages = ";
        cout << prec(3) << (double)((double)cc/(double)(sz(st)*(sz(st)-1))) << " clicks\n";
    }
}
