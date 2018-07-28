#define NUM 10000007
bool flag[NUM];
ll prefac[NUM];
void seive()
{
    flag[1]=true;
    prefac[1]=0;
    prefac[2]=2;
    prefac[3]=3;
    ll i;
    for(i=4; i<NUM; i+=2)
    {
        flag[i]=true;
        prefac[i]=2;
    }
    for(i=3; i*i<=NUM; i+=2)
    {
        if(!flag[i])
        {
            for(ll j=i*i; j<NUM; j+=2*i)
            {
                flag[j]=true;
                prefac[j]=i;
            }
        }
    }
    for(; i<NUM; i+=2)
        if(!flag[i])
            prefac[i]=i;
    return;
}

void prfac(ll x)
{
    while(x>1)
    {
        if(!flag[x])
        {
            cout << x << " ";
            x=1;
        }
        else
        {
            cout << prefac[x] << " ";
            x/=prefac[x];
        }
    }
    return;
}

ll n;

int main()
{
    //Fast
    seive();
    cin >> n;
    prfac(n);
}
