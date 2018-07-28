#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
int countSubstringWithEqualEnds(string s)
{
    int result = 0;
    int n = s.length();
    int count[256] = {0};
    for (int i=0; i<n; i++) count[s[i]]++;
    for (int i=0; i<MAX_CHAR; i++)
        result += (count[i]*(count[i]+1)/2);

    return result;
}

int main()
{
    string s("11001");
    cout << countSubstringWithEqualEnds(s);
    return 0;
}
