#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,yb[10][10] = {{1,0,0,0,0,0,0,0,0,0},{2,1,0,0,0,0,0,0,0,0},{3,2,1,0,0,0,0,0,0,0},{4,3,2,1,0,0,0,0,0,0},{5,4,3,2,1,0,0,0,0,0},{6,5,4,3,2,1,0,0,0,0},{7,6,5,4,3,2,1,0,0,0},{8,7,6,5,4,3,2,1,0,0},{9,8,7,6,5,4,3,2,1,0},{10,9,8,7,6,5,4,3,2,1}};
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    int xr = a[1];
    sort(a + 1,a + n*m + 1,cmp);
    int pos = 0;
    for (int i = 1;i <= n * m;i++)
    {
        if (a[i] == xr)
        {
            pos = i;
            break;
        }
    }
    int c = pos / n + 1,r = 0;
    if (pos % n == 0)
    {
        c--;
        r = n;
        cout << c << " " << r;
        return 0;
    }
    if ((pos / n) % 2 == 0)
    {
        if (pos % n == 0)
            r = n;
        else
            r = pos % n;
    }
    else
    {
        int x = pos % n;
        if (x == 0)
        {
            x = n;
        }
        r = yb[n][x];
    }
    cout << c << " " << r;
	return 0;
}
