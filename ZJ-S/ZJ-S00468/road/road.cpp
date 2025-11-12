#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int M=1e3+100;
struct node
{
	int a1,a2,a3;
}a[N];
int ans;
bool cmp(node x,node y)
{
	return x.a3<y.a3;
}
int fa[M];
int find(int x)
{
	if(fa[x]==x)
	return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int p;
int n,m,k;
int e[M][M];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>e[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>e[i][j];
		}
	}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
		//	cout<<a[i].a3<<endl;
			if(find(a[i].a1)!=find(a[i].a2))
			{
				fa[find(a[i].a1)]=find(a[i].a2);
				p++;
				ans+=a[i].a3;
			}
			if(p==n-1)
			{
				break;
			}
		}
		cout<<ans;
	return 0;
}
