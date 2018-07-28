#include<bits/stdc++.h>
using namespace std;
#define NUM 100005
bool flag[NUM];
vector <long long> prime;
void seive()
{
    flag[1]=true;
    for(long long i=4;i<NUM;i+=2) flag[i]=true;
    for(long long i=3;i*i<=NUM;i+=2) if(!flag[i])for(long long j=i*i;j<NUM;j+=2*i) flag[j]=true;
    prime.push_back(2);
    for(long long i=3;i<NUM;i+=2) if(!flag[i]) prime.push_back(i);
    return;
}

long long store_primes[100],freq_primes[100], store_divisor[10000], Total_Prime, ans;

void divisor(long long N)
{
    	long long i,val,count;

    	val=sqrt(N)+1;
    	Total_Prime=0;
    	for(i=0;prime[i]<val;i++)
    	{
       	if(N%prime[i]==0)
        	{
            		count=0;
            		while(N%prime[i]==0)
            		{
                		N/=prime[i];
                		count++;
            		}
            		store_primes[Total_Prime]=prime[i];
            		freq_primes[Total_Prime]=count;
            		Total_Prime++;
			val=sqrt(N)+1;     // sqrt again for fast compute.
        	}
    	}
    	if(N>1)
    	{
       	store_primes[Total_Prime]=N;
        	freq_primes[Total_Prime]=1;
        	Total_Prime++;
    	}
}
void Generate(long long cur,long long num)
{
    long long i,val;

    if(cur==Total_Prime)
    {
        store_divisor[ans++]=num;
    }
    else
    {
        val=1;
        for(i=0;i<=freq_primes[cur];i++)
        {
            Generate(cur+1,num*val);
            val=val*store_primes[cur];
        }
    }
}
int main()
{
    	seive();
    	long long n,i;

    	while(scanf("%lld",&n)==1)
    	{
       	divisor(n);
        	ans=0;
        	Generate(0,1);
        	sort(&store_divisor[0],&store_divisor[ans]);

        	printf("Total No of Divisors: %lld\n",ans);
        	for(i=0;i<ans;i++)
            		printf("%lld ",store_divisor[i]);
        	printf("\n");
    	}
    	return 0;
}
