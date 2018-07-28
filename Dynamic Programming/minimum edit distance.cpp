ll mineditdis(string s1,string s2,ll x,ll y)
{
    if(!x) return y;
    if(!y) return x;
    if(s1[x-1]==s2[y-1]) return mineditdis(s1,s2,x-1,y-1);
    return 1+min3(mineditdis(s1,s2,x,y-1),mineditdis(s1,s2,x-1,y),mineditdis(s1,s2,x-1,y-1));
}

//Insert mineditdis(s1,s2,x,y-1)
//Remove mineditdis(s1,s2,x-1,y)
//Replace mineditdis(s1,s2,x-1,y-1)

int main()
{
    Fast
    string s1,s2;
    cin >> s1 >> s2;
    cout << mineditdis(s1,s2,sz(s1)-1,sz(s2)-1) << "\n";
}
