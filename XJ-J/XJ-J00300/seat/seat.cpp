#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],x,l,T;
int hang,lie;
int w;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    x = m * n;
    cin >> n >> m;
    cin >> l;
    for(int i = 1;i <= n * m - 1;i++)
    {
        cin >> a[i];
    }
    a[m * n] = l;
    sort(a+1,a+n*m+1);
    for(int i = 1;i <= n * m;i++)
    {
        if(a[i] == l)
        {
            T = i;
            break;
        }
    }
    T = m * n - T + 1;
    for(int i = 1;i <= m;i++)  //ÐÐnÁÐm
    {

        if(i % 2 == 0)
        {
            x = i * n;
            for(int j = 1;j <= n;j++)
            {
                if(x == T)
                {
                    cout << i << " " << j;
                    break;
                }
                else
                {
                    x -= 1;
                }
            }
        }
        else
        {
            x = (i - 1) * n + 1;
            for(int j = 1;j <= n;j++)
            {
                if(x == T)
                {
                    cout << i << " " << j;
                    break;
                }
                else
                {
                    x += 1;
                }
            }
        }
    }
    return 0;
}
