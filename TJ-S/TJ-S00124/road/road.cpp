#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int inf = 100000000000;
int u,v;
int w[200005];
long long res;
int f[50][50][50];
int a;
struct pic
{
    int to,val;	
};
vector <pic> edge[200005];
void dfs(int i, int x, int y, int z, long long w)
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
	//if(x>0) dfs(i + 1, x - 1, y, z, w + a[i][1]);
	//if(y>0) dfs(i + 1, x, y - 1, z, w + a[i][2]);
	//if(z>0) dfs(i + 1, x, y, z - 1, w + a[i][3]);
}
//void no_use()
//{
	//for (int i = 1; i <= 5; i++)
	//{
		//memset(a[i], 0, sizeof(a[i]));
	//}
	//for(int i=1;i<=32;i++)
	//{
		//for(int j=1;j<=32;j++)
		//{
			//for(int k=1;k<=32;k++)
			//{
				//f[i][j][k]=0;
			//}
		//}
	//}
	//memset(b,0,sizeof(b));
	//for (int i = 1; i <= n; i++)
	//{
		//cin >> a[i][1] >> a[i][2] >> a[i][3];
		//b[i]=a[i][1];
		//if(a[i][2]!=0)
		//{
		//	flag1=0;
		//}
//		if(a[i][3]!=0)
//		{
//			flag2=0;
//		}
//	}
//	int maxx = n / 2;
//	if(flag1==1)
//	{
//		sort(b+1,b+n+1);
//		for(int i=n;i>maxx;i--)
//		{
//			res+=b[i];
//		}
//		cout<<res<<endl;
//	}
//	else if(flag2==1)
//	{
//		memset(b,0,sizeof(b));
//		for(int i=1;i<=n;i++)
//		{
//			res+=a[i][1];
//			b[i]=a[i][2]-a[i][1];
//		}
//		sort(b+1,b+n+1);
//		for(int i=n;i>maxx;i--)
//		{
//			res+=b[i];
//		}
//		cout<<res<<endl;
//	}
//	else
//	{
//	    dfs(0, maxx, maxx, maxx, 0);
//	    cout << res << endl;
//	}
//}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w[i];
		pic tmp;
		tmp.to=v;
		tmp.val=w[i];
	}
	long long res=0;
	for(int i=1;i<=m;i++)
	{
		res+=w[i];
	}
	cout<<res<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
