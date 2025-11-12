#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
int n;
struct node
{
	int a,b,c;
};
node s[100001];
int f[101][101][101];
bool cmp(node x,node y)
{
	return x.a - x.b > y.a - y.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool judge = 1;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].c != 0) judge = 0;
		}
		if(judge)
		{
			sort(s + 1,s + n + 1,cmp);
			int ans = 0;
			for(int i = 1;i <= n / 2;i++)
			{
				ans += s[i].a;
			}
			for(int i = n / 2 + 1;i <= n;i++)
			{
				ans += s[i].b;
			}
			cout << ans << endl;
			continue;
		}
		if(n <= 200)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = 0;j <= n / 2;j++)
				{
					for(int k = 0;k <= n / 2;k++)
					{
						int l = i - j - k;
						if(l > n / 2) continue;
						if(j != 0) f[j][k][l] = max(f[j][k][l],f[j - 1][k][l] + s[i].a);
						if(k != 0) f[j][k][l] = max(f[j][k][l],f[j][k - 1][l] + s[i].b);
						if(l != 0) f[j][k][l] = max(f[j][k][l],f[j][k][l - 1] + s[i].c);
					}
				}
			}
			int ans = 0;
			for(int i = 0;i <= n / 2;i++)
			{
				for(int j = 0;j <= n / 2;j++)
				{
					int k = n - i - j;
					if(k > n / 2) continue;
					ans = max(ans,f[i][j][k]);
				}
			}
			cout << ans << endl;
			memset(f,0,sizeof(f));
			continue;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int k = max(s[i].a,s[i].b);
			ans += max(k,s[i].c);
		}
		cout << ans << endl;
	}
}
