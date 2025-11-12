#include<bits/stdc++.h>
using namespace std;
int n, m, b, d, i = 1, j = 1, ans = 1;
int a[110];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    d = n * m;
    for(int i = 1; i <= d; i++)
    {
        cin >> a[i];
    }
    b = 1;
    for(int i = 2; i <= d; i++)
    {
        if(a[i] > a[1])
        {
            b++;
        }
    }
    while(d--)
    {
        if(j % 2 == 0)
        {
            if(i == 1)
            {
                j++;
                i++;
            }
            i--;
            ans++;
        }
        else
        {
            if(i == n)
            {
                j++;
                i--;
            }
            i++;
            ans++;
        }
        if(ans == b)
        {
            cout << j << " " << i;
        }
    }
    return 0;
}
