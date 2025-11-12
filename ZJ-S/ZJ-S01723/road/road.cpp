#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
struct edg
{
	int fr,to,cos;
}edge[maxn];
int tot=0,fa[maxn];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int a,int b,int c)
{
	tot++;
	edge[tot].fr=a;
	edge[tot].to=b;
	edge[tot].cos=c;
}
bool cmp1(edg x,edg y)
{
	return x.cos<y.cos;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k,x,y,z,res;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}m*=2;
	sort(edge+1,edge+1+m,cmp1);
	for(int i=1;i<=k;i++){}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1,vis=0;i<=m&&vis<n;i++)
	{
		if(find(fa[edge[i].fr])!=find(fa[edge[i].to]))
		{
			vis++;
			res+=edge[i].cos;
			fa[edge[i].fr]=fa[edge[i].to];
		}
	}
	cout << res << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
