#include<bits/stdc++.h>
using namespace std;
const int M=1000005;
int n,m,k;
long long cnt;
int c[15];

int father[M];
int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
void connect(int x,int y)
{
	x=find(x);
	y=find(y);
	father[x]=y;
	return ;
}
bool check(int x,int y)
{
	if(find(x)==find(y))return true;
	else return false;
}

struct edge{
	int head;
	int tail;
	int k;
}a[M];

bool cmp(edge x,edge y)
{
	return x.k<y.k;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		a[i].head=u;
		a[i].tail=v;
		a[i].k=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&k);
		}
	}
	sort(a+1,a+m+1,cmp);
	int num=0;
	for(int i=1;i<=m;i++)
	{
		if(check[a[i].head]!=check[a[i].tail])
		{
			num++;
			connect(a[i].head,a[i].tail);
			cnt+=a[i].k;
			if(num==n-1)break;
		}
	}
	cout<<cnt;
	return 0;
}
