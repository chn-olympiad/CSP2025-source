#include<bits/stdc++.h>
using namespace std;
int t, n;
int a[200005][5];
int b[200005];
int f[32][32][32]; 
int res;
bool flag1=1,flag2=1;
void dfs(int i, int x, int y, int z, int w)
{
	if(w<f[x][y][z])
	{
		return;
	}
	res = max(res, w);
	if (i > n)
	{
		return;
	}
	f[x][y][z]=w;
	if(x>0) dfs(i + 1, x - 1, y, z, w + a[i][1]);
	if(y>0) dfs(i + 1, x, y - 1, z, w + a[i][2]);
	if(z>0) dfs(i + 1, x, y, z - 1, w + a[i][3]);
	return;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		res=0;
		for (int i = 1; i <= 3; i++)
		{
			memset(a[i], 0, sizeof(a[i]));
		}
		for(int i=1;i<=32;i++)
		{
			for(int j=1;j<=32;j++)
			{
				for(int k=1;k<=32;k++)
				{
					f[i][j][k]=0;
				}
			}
		}
		memset(b,0,sizeof(b));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i]=a[i][1];
			if(a[i][2]!=0)
			{
				flag1=0;
			}
			if(a[i][3]!=0)
			{
				flag2=0;
			}
		}
		int maxx = n / 2;
		if(flag1==1)
		{
			sort(b+1,b+n+1);
			for(int i=n;i>maxx;i--)
			{
				res+=b[i];
			}
			cout<<res<<endl;
		}
		else if(flag2==1)
		{
			memset(b,0,sizeof(b));
			for(int i=1;i<=n;i++)
			{
				res+=a[i][1];
				b[i]=a[i][2]-a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>maxx;i--)
			{
				res+=b[i];
			}
			cout<<res<<endl;
		}
		else
		{
		    dfs(0, maxx, maxx, maxx, 0);
		    cout << res << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
