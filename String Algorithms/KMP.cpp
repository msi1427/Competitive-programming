vector<ll> prefix_function (string Z)
{
    ll n = (ll) Z.length();
    vector<ll> F (n);
    F[0]=0;
    for (ll i=1; i<n; ++i)
    {
        ll j = F[i-1];
        while (j > 0 && Z[i]!=Z[j])
            j=F[j-1];
        if (Z[i]==Z[j])
            ++j;
        F[i] = j;
    }
    return F;
}

ll KMP(string s1,vector<ll>pr,string s2)
{
    ll c=0;
    for(int i=0,j=0; i<sz(s1);)
    {
        if(s1[i]==s2[j]) i++,j++;
        else
        {
            while(j>0 && s1[i]!=s2[j]) j=pr[j-1];
            if(j==0 && s1[i]!=s2[j]) i++;
        }
        if(j==sz(s2))
        {
            c++;
            while(j>0 && s1[i]!=s2[j]) j=pr[j-1];
        }
    }
    return c;
}

string s1,s2;

int main()
{
    Fast
    cin >> s1;
    cin >> s2;
    vector<ll>pr=prefix_function(s2);
    cout << KMP(s1,pr,s2) << "\n";
}

/*
abxabcabcaby
ab
*/
