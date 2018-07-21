#define maxx 100005
bitset<maxx>vis;
vector<int>prime;
void sieve()
{
    int x=maxx/2, y=sqrt(maxx)/2;
    for(int i=1;i<=y;i++)
    {
        if(vis[i])
        {
            for(int j=(i*(i+1))*2;j<=x;j+=(2*i)+1)
                vis[j]=1;
        }
    }
    prime.pb(2);
    for(int i=3;i<maxx;i+=2)
        if(vis[i/2]==0)
            prime.pb(i);
}

int segmented_sieve(int a, int b)
{
    vis=0;
    if(b<2) return 0;
    if(a<2) a=2;
    int xx=sqrt((double)b)+1;
    for(ll i=0;i<SZ(prime) && prime[i]<=xx;i++)
    {
        ll j=(a/prime[i]);
        if(a%prime[i]!=0) j++;
        j*=prime[i];
        if(j==prime[i]) j+=prime[i];
        for(;j<=b;j+=prime[i])
            vis[j-a]=1;
    }
    int cnt=0;
    for(ll i=a;i<=b;i++)
        if(vis[i-a]==0) cnt++;
    return cnt;
}

int main()
{

    sieve();
    
        printf("%d\n",segmented_sieve(a,b));
    
}

//Alternative

vector<long long> prime;
vector<long long> seg;
void simpleSieve(long long limit)
{
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (long long p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (long long i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (long long p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            //cout << p << "  ";
        }
    }
}
void segmentedSieve(long long n)
{
    long long limit = floor(sqrt(n))+1;
    simpleSieve(limit);
    long long low  = limit;
    long long high = 2*limit;
    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (long long i = 0; i < prime.size(); i++)
        {
            long long loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (long long j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        for (long long i = low; i<high; i++)
            if (mark[i - low] == true)
            {
                //cout << i << "  ";
                seg.push_back(i);
            }
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}
