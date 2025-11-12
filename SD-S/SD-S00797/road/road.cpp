#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,M=1e4+3;
int a[M],c[10][M];
struct node{
	int u,v;
	long long w;
}p[N*10];
bool operator<(const node& a,const node& b)
{
	return a.w<b.w;
}
//bool operator>(const node& a,const node& b)
//{
//	return a.w>b.w;
//}
//bool operator==(const node& a,const node& b)
//{
//	return a.w==b.w;
//}
//bool cmp(node a,node b)
//{
//	return a.w>b.w;
//}
int findd(int noww)
{
	if(a[noww]!=noww)
	{
		return findd(a[noww]);
	}
	return a[noww];
}
int n,m,k,js,cnt; 
long long ans;
inline int cinn()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=cinn();
	m=cinn();
	k=cinn();
	node wh;
	for(int i=0;i<m;i++)
	{
		wh.u=cinn();
		wh.v=cinn();
		wh.w=(long long)cinn();
		p[js++]=wh; 
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	int num; 
	for(int i=0;i<k;i++)
	{
		c[i][0]=cinn();
		for(int j=1;j<=n;j++)
		{
			c[i][j]=cinn();
		}
		for(int j=1;j<=n;j++)
		{
			for(int ii=j+1;ii<=n;ii++)
			{
				wh.u=j;
				wh.v=ii;
				wh.w=0ll+c[i][0]+c[i][j]+c[i][ii];
				p[js++]=wh;
			}
		}
	}
	sort(p,p+js);
	int i=0;
	while(cnt<n-1)
	{
		wh=p[i];
		i++;
		a[wh.u]=findd(a[wh.u]);
		a[wh.v]=findd(a[wh.v]);
		if(a[wh.u]!=a[wh.v])
		{
			cnt++;
			ans+=wh.w;
			a[wh.u]=a[a[wh.v]];
		}
	}
	cout<<ans<<endl;
	return 0;
}
