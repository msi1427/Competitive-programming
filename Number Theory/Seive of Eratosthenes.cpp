/* Seive of Eratosthenes */
#define NUM 100005
bool flag[NUM];
vector <ll> prime;
void seive()
{
    flag[1]=true;
    for(int i=4;i<NUM;i+=2) flag[i]=true;
    for(int i=3;i*i<=NUM;i+=2) if(!flag[i])for(int j=i*i;j<NUM;j+=2*i) flag[j]=true;
    prime.push_back(2);
    for(int i=3;i<NUM;i+=2) if(!flag[i]) prime.push_back(i);
    return;
}
void PF()
{
    for(ll i=2;i<NUM;i++) if(!flag[i]) for(ll j=i*2;j<NUM;j+=i) fac[j].pb(i);
}
