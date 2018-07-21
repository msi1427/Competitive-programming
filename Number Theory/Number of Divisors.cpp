#include<bits/stdc++.h>
using namespace std;
#define NUM 1000005
bool flag[NUM];
vector <int> prime;
void seive()
{
    flag[1]=true;
    for(int i=4;i<NUM;i+=2)
    {
        flag[i]=true;
    }
    for(int i=3;i*i<=NUM;i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*i;j<NUM;j+=2*i)
            {
                flag[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<NUM;i+=2)
    {
        if(!flag[i])
        {
            prime.push_back(i);
        }
    }
    return;
}

int divisor(int N)
{
    int i,count,sum;
    sum=1;
    for(i=0; prime[i]*prime[i]<=N && i<sz(prime); i++)
    {
        if(N%prime[i]==0)
        {
            count=0;
            while(N%prime[i]==0)
            {
                N/=prime[i];
                count++;
            }
            sum*=(count+1);
        }
    }
    if(N>1)
        sum=sum*2;
    return sum;
}
int main()
{
    seive();
    int n;
    scanf("%d",&n);
    printf("%d",divisor(n));
}
