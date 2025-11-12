#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],used[5005],cnt;
void dfs(long long w,long long x,long long y,long long z)
{
    if(w == x)
    {
        if(y > z * 2)
        {
            cnt++;
            cnt %= 998244353;
        }
    }
    if(w == x)
    {
        return ;
    }
    for(long long i = 1;i <= n;i++)
    {
        used[i] = 1;
        z = max(z,a[i]);
        dfs(w + 1,x,y += a[i],z);
        used[i] = 0;
    }
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    if(n <= 2)
    {
        cout << 0;
    }
    if(n == 3)
    {
        if(a[1] + a[2] > a[3])
        {
            cnt++;
        }
        cout << cnt;
    }
    else
    {
        for(long long i = 3;i <= n;i++)
        {
            dfs(0,i,0,0);
        }
        cout << cnt;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
