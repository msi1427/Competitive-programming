vector<ll>v,tail;
ll n;

ll BS(ll l, ll r, ll key)
{
    while (r - l > 1) {
        ll m = l + (r - l) / 2;
        if (tail[m] >= key) r = m;
        else l = m;
    }
    return r;
}

ll LIS()
{
    if (v.size() == 0) return 0;
    ll length = 1;
    tail[0] = v[0];
    for (ll i = 1; i < v.size(); i++) {
        if (v[i] < tail[0]) tail[0] = v[i];
        else if (v[i] >= tail[length - 1]) tail[length++] = v[i];
        else tail[BS(-1, length - 1, v[i])] = v[i];
    }
    return length;
}

int main()
{
    cin>>n;
    v.resize(n);
    tail.resize(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    cout << "Length of LIS is " << LIS() << '\n';
}
