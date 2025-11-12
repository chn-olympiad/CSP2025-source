#include <bits/stdc++.h> 
#define endl '\n'
using namespace std;
int n,m,k,u[1100025],v[1100025],w[1100025],c[15],a[15][10005],l;
long long sum,minn[100005];
bool x[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		//t[u[i]]++;
		//t[v[i]]++;
	}
	for (int i=1;i<=k;i++)
	{
		cin >> c[i];
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		minn[i]=10e9+3;
		if(!x[i])
		{
			for (int j=1;j<=m;j++)
			{
				if(u[j]==i && minn[i]>w[j])
				{
					l=v[j];
					minn[i]=w[j];
				}
				if(v[j]==i && minn[i]>w[j])
				{
					l=u[j];
					minn[i]=w[j];
				}
			}
			for (int j=1;j<=k;j++){
				if(minn[i]>c[j]+a[j][i]+a[j][l])
					minn[i]=c[j]+a[j][i]+a[j][l];
			}
			x[i]=true;x[l]=true;
			sum+=minn[i]; 
		}
	}
	cout << sum;
	return 0;
}
