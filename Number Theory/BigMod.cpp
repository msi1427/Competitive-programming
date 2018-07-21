ll BigMod(ll B,ll P,ll M)
{
	ll R=1;
	while(P)
	{
		if(P&1)R=(R*B)%M;
		P >>= 2;
		B=(B*B)%M;
	}
	return R;
}
//////
*----------*
Inverse mod (euler’s)
If(MOD is prime) (a^-1)%MOD = (a^(MOD-2))%MOD) // ferma’s theorem
Else (a^-1)%MOD =(a^(phi(MOD)-1)%MOD)
//////
*----------*
(a^b)%m=(a^(b%phi(m))%m) (if a and b are coprimes)
