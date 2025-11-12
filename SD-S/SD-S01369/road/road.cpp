#include <bits/stdc++.h>
using namespace std;
int n,m,k,b[15],l[15],fa[100010];
long long ans;
struct T{
	int x,y,t;
}a[2000005];
bool cmp(T p,T q)
{
	return p.t<q.t;
}
int fi(int x)
{
	return x==fa[x]?x:fa[x]=fi(fa[x]);
}
bool merge(int x,int y)
{
	int fx=fi(x);int fy=fi(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
		return true;
	}
	return false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n+k;i++)fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].t;
	}
	for (int i=1;i<=k;i++)
	{
		cin >> l[i];
		for (int j=1;j<=n;j++)
		{
			a[m+n*(i-1)+j].x=n+i;a[m+n*(i-1)+j].y=j;
			cin >> a[m+n*(i-1)+j].t;a[m+n*(i-1)+j].t+=l[i];
		}
	}
	sort(a+1,a+m+n*k+1,cmp);
	int num=n;
	for (int i=1;i<=m+n*k;i++)
	{
		//cout << a[i].t << endl;
		if(merge(a[i].x,a[i].y))
		{
			num--;
			if(a[i].x>n)
			{
				if(!b[a[i].x-n])
				{
					num++;
					ans+=l[a[i].x-n];
					b[a[i].x-n]=1;
				}
				ans+=a[i].t-l[a[i].x-n]; 
			}
			else {
				ans+=a[i].t;
			}
			//cout << ans << endl;
		}
		if(num==1)
		{
			cout << ans;
			return 0;
		}
	}
	//cout << ans;
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
