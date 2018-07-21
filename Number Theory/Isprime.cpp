bool isprime(ll n)
{
    for(ll i=2;i<=(ll)(sqrt(n));i++) if(n%i==0) return false;
    return true;
}
