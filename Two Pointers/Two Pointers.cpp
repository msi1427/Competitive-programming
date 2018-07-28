//(finding out the minimum distance where all the distinct characters of a string can be found)
ll n,c,mn=INF;
string s;
set < char > st;
map < char , ll > mp;

int main()
{
    Fast
    cin >> n;
    cin >> s;
    FLR(i,sz(s)) st.insert(s[i]);
    ll ss = sz(st);
    ll i=-1,j=-1;
    while(true)
    {
        if(c<ss)
        {
            j++;
            if(j==n) break;
            if(!mp[s[j]]) c++;
            mp[s[j]]++;
        }
        else
        {
            mn=min(mn,j-i);
            i++;
            if(i==n) break;
            mp[s[i]]--;
            if(!mp[s[i]]) c--;
        }
    }
    cout << mn << endl;
}
