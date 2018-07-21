#include<bits/stdc++.h>
using namespace std;
int mult[10][10];
int main()
{
    int a[10][10], b[10][10], r1, c1, r2, c2, i, j, k;
    r1=r2=c1=c2=2;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cin >> a[i][j];
        }
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cin >> b[i][j];
        }
    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << " " << mult[i][j];
        }
}
