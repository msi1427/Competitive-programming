const ull hs = 99991;
ull F[MAX];
ll n;
vector<string>vs;

int main()
{
    Fast
    F[0] = 1;
    for(ll i = 1; i < MAX; i++) F[i] = (F[i - 1] * hs)%MOD;
    cin>>n;
    FLR(i,n) {
        string s;
        cin>>s;
        vs.pb(s);
    }
    string ans = vs[0];
    repl(i,1,n-1){
        string ss = vs[i];
        ull H=0,G=0;
        ll pos = 0;
        for(ll j=0;j<min((ll)sz(ans),(ll)sz(ss));j++)
        {
            H = H + F[j] * ans[sz(ans)-1-j];
            G = G * hs + ss[j];
            H%=MOD;
            G%=MOD;
            if(H==G) pos=j+1;
        }
        repl(j,pos,sz(ss)-1) ans+=ss[j];
    }
    cout << ans << "\n";
}
/*
4
sample amples samples sam
*/
