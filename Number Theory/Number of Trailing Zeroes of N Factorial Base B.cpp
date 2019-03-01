#define NUM 1000005
bool flag[NUM];
vector <ll> prime;
void sieve()
{
    flag[1]=true;
    for(ll i=4;i<NUM;i+=2) flag[i]=true;
    for(ll i=3;i*i<=NUM;i+=2) if(!flag[i])for(ll j=i*i;j<NUM;j+=2*i) flag[j]=true;
    prime.push_back(2);
    for(ll i=3;i<NUM;i+=2) if(!flag[i]) prime.push_back(i);
    return;
}

ll factors_in_factorial(ll N,ll p)
{
    	ll sum=0;
    	while(N)
    	{
            sum+=N/p;
            N/=p;
    	}
    	return sum;
}

ll Trailingzero_Base_B(ll N,ll B)
{
    	ll i,freq,power;
    	ll ans = 1e18;
    	for(i=0;prime[i]<=B && i<sz(prime);i++)
    	{
       	if(B%prime[i]==0)
        	{
            		freq=0;
            		while(B%prime[i]==0)
            		{
                		freq++;
                		B/=prime[i];
            		}
            		power=factors_in_factorial(N,prime[i]);
            		ans=min(ans,power/freq);
        	}
    	}
    	if(B>1){
            power=factors_in_factorial(N,B);
            ans=min(ans,power);
    	}
    	return ans;
}

ll n,b;

int main()
{
    	sieve();
    	cin>>n>>b;
    	cout <<  Trailingzero_Base_B(n,b) << "\n";
}
