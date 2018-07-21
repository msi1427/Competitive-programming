ll T,n,p;

ll T_Z(ll N)
{
    if(N<=0) return 0;
    return (N/5)+T_Z(N/5);
}

int main()
{
    Fast
    cin >> T;
    while(T--)
    {
        cin >> n;
        casep(++p);
        cout << T_Z(n) << endl;
    }
}
