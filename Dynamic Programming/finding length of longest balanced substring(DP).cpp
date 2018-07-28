
ll get_ans(string &s)
{
    vector<ll> dp(n+1);
    unordered_map<ll,ll> mp;
    ll i,bal=0,mx=-1;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0') bal--;
        else bal++;
        dp[i+1]=bal;
    }
    for(i=n;i>=0;i--)
    {
        if(mp.find(dp[i])!=mp.end()) mx=max(mx,mp[dp[i]]-i);
        else mp[dp[i]]=i;
    }
    return mx;
}
