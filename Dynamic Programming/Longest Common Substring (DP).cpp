string s1,s2;
ll dp[100][100],mx;

ll lcstr()
{
    FLR(i,sz(s1))
    {
        FLR(j,sz(s2))
        {
            if(s1[i]==s2[j])
            {
                if(i==0 && j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+1;
            }
            mx = max(mx,dp[i][j]);
        }
    }
    return mx;
}

int main()
{
    Fast
    cin >> s1 >> s2;
    cout << lcstr() << "\n";
}
