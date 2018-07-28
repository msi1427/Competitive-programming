struct job
{
    ll st,en,pr;
}a[100];

ll dp[100],n;

bool cmp(job i,job j)
{
    if(i.en<j.en) return true;
    return false;
}

int main()
{
    Fast
    cin >> n;
    FLR(i,n) {
        cin >> a[i].st >> a[i].en >> a[i].pr;
        dp[i]=a[i].pr;
    }
    sort(a,a+n,cmp);
    ll mx = -INF;
    FLR(i,n)
    {
        FLR(j,i)
        {
            if(a[j].en<=a[i].st)
            {
                dp[i]=max(dp[i],dp[j]+a[i].pr);
            }
        }
        mx = max(mx,dp[i]);
    }
    cout << mx << "\n";
}
/*
6
1 3 5
2 5 6
4 6 5
6 7 4
5 8 11
7 9 2
*/
