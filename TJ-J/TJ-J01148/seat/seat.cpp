#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105];
    int n ,m;
    int c = 1,r = 1;
    for(int i = 1;i <= n * m;i++)
    {
    	cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(a[j] < a[j+1])
            {
                r += 1;
                if(r > n)
                {
                    c += 1;
                    r = 1;
                }
            }
        }
    }
    cout << c << r;
    return 0;
}
