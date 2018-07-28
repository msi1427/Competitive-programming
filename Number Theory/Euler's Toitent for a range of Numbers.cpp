#include<bits/stdc++.h>
using namespace std;
#define NUM 1000005
long long phi[NUM];
void phi_seive()
{
    for(long long i=1;i<NUM;i++) phi[i]=i;
    for(long long i=2;i<NUM;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(long long j=2*i;j<NUM;j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
    return;
}
int main()
{
    phi_seive();
    for(long long i=1;i<=99;i++) cout<<i<<" " << phi[i]<< endl;
}
