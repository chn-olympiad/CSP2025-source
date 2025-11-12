#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],b[15][15],r,weizhi;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    r = a[1];
    //cout << r << endl;
    sort(a + 1,a + (n * m) + 1);
    for(int i = 1;i <= n * m;i++)
    {
        if(a[i] == r)
        {
            weizhi = i;
        }
    }
    //cout << weizhi << endl;
    weizhi = (n * m) - weizhi + 1;
    for(int i = 1;i <= m;i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1;j <= n;j++)
            {
                b[j][i] = (i - 1) * n + j;
            }
        }
        else
        {
            for(int j = 1;j <= n;j++)
            {
                b[j][i] = (i * n) - j + 1;
            }
        }
    }
    /*cout << weizhi << endl;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }*/
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(b[i][j] == weizhi)
            {
                cout << j << " " << i << endl;
            }
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
