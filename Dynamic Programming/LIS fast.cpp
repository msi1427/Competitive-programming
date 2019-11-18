vector<ll>v,tail;
ll n;

ll LIS()
{
    if (v.size() == 0) return 0;
    ll length = 1;
    tail[0] = v[0];
    for (ll i = 1; i < v.size(); i++) {
        auto b = tail.begin(), e= tail.begin()+length;
        auto it = lower_bound(b,e,v[i]);
        if(it == tail.begin()+length) tail[length++]=v[i];
        else *it = v[i];
    }
    return length;
}

ll k1,k2,k3,x;

int main()
{
    Fast
    cin>>k1>>k2>>k3;
    n=k1+k2+k3;
    v.resize(n);
    tail.resize(n);
    FLR(i,k1){
        cin>>x;
        v[x-1]=1;
    }
    FLR(i,k2){
        cin>>x;
        v[x-1]=2;
    }
    FLR(i,k3){
        cin>>x;
        v[x-1]=3;
    }
    cout << n-LIS() << "\n";

}
