string s1,s2;
ll dp[100][100];
void lcs(string s1,string s2)
{
    FLR(i,sz(s1)+1)
    {
        FLR(j,sz(s2)+1)
        {
            if(i==0||j==0) dp[i][j]=0;
            else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[sz(s1)][sz(s2)] << "\n";
    string LCS;
    ll i=sz(s1),j=sz(s2);
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            LCS.pb(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    REV(LCS);
    cout << LCS << "\n";
    return;
}

int main()
{
    cin >> s1 >> s2;
    lcs(s1,s2);
}

// minimum number of edits needed to make a string palindrome s.length() - lcs( s , sreverse )
