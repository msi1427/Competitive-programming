ll T,n,k;

int main()
{
    scl(T);
    repl(tc,1,T){
    scl(n);
    scl(k);
    double xx = (double)k*(log10((double)n));
    xx -= (ll)xx;
    xx = pow(10.0,xx);
    xx *= 100;
    ll yy = BMod(n,k,1000);
    cout << "Case " << tc << ": " << (ll)xx << " "  << setw(3) << setfill('0')<< yy << "\n";
    }
}
