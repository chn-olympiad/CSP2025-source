#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][5], p[N], now, ch[5], s[N], cur;

int Main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=3;j++) scanf("%d", &a[i][j]);
		int mx = a[i][1], u = 1;
		for(j=2;j<=3;j++) if(a[i][j]>mx) mx = a[i][j], u = j;
		p[i] = u, now += mx, ch[u]++;
	}
	for(i=1;i<=3;i++) if(ch[i]>n/2)
	{
		int x = i;
		for(i=1;i<=n;i++) if(p[i]==x)
		{
			int mx = -1;
			for(j=1;j<=3;j++) if(j!=x&&a[i][j]>mx) mx = a[i][j];
			s[++cur] = a[i][x] - mx;
		}
		sort(&s[1],&s[cur]+1);
		for(i=1;i<=ch[x]-n/2;i++) now -= s[i];
		break;
	}
	printf("%d\n", now);
	now = cur = 0;
	for(i=1;i<=3;i++) ch[i] = 0;
	return 0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d", &t);
	while(t--) Main();
	return 0;
}