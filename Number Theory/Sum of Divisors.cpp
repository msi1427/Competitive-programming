#define NUM 1000005

bool flag[NUM];
vector <int> prime;
void seive()
{
    flag[1]=true;
    for(int i=4;i<NUM;i+=2) flag[i]=true;
    for(int i=3;i*i<=NUM;i+=2)
    {
        if(!flag[i]) for(int j=i*i;j<NUM;j+=2*i) flag[j]=true;
    }
    prime.pb(2);
    for(int i=3;i<NUM;i+=2) if(!flag[i]) prime.pb(i);
    return;
}
int Sum_Of_Divisor(int N)
{
    	int i,count,sum,p,s;
    	sum=1;
    	for(i=0;prime[i]*prime[i]<=N && i<prime.size();i++)
    	{
       	if(N%prime[i]==0)
        	{
            		p=1;
            		while(N%prime[i]==0)
            		{
                		N/=prime[i];
                		p=p*prime[i];
            		}
            		p=p*prime[i];
            		s=(p-1)/(prime[i]-1);
            		sum=sum*s;
        	}
    	}

	if(N>1)
    	{
       	p=N*N;
        	s=(p-1)/(N-1);
        	sum=sum*s;
    	}
    	return sum;
}

int main()
{
    	seive();
    	int n;

    	while(scanf("%d",&n)==1)
    	{
       	printf("%d Sum of Of divisor:%d\n",n,Sum_Of_Divisor(n));
    	}
    	return 0;
}
