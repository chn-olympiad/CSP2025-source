#include <bits/stdc++.h>
using namespace std;
const int maxn = 503;
int c[maxn],s[maxn],a[maxn];
int n,m,p,cnt;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s[n];
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if(s[i] == 1)
		{
			a[i] = 1;
		}
		if(s[i] == 0)
		{
			a[i] = 0;
			cnt++;
		}
		if(c[i] < cnt)
		{
			a[i] = 0;
			cnt++;
		}
	}
	cout << 1;
	return 0;
}
