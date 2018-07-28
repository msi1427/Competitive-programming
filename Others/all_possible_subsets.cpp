void possible_subsets(string s,ll x)
{
    FLR(i,(1<<x))
    {
        FLR(j,x) if(i&(1<<j))cout << s[j];
        cout << "\n";
    }
}

int main()
{
    //Fast
    string s;
    cin >> s;
    possible_subsets(s,sz(s));
}
