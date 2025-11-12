#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}

long long f[100005],w[100005],c[15][10005],C[15],now;
long long sum,k,m,n;
struct node
{
	long long u,v,w;
}e[1200005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long find(long long x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
void hb(long long x,long long y)
{
	x=find(x),y=find(y);
	if(w[x]<w[y])
	{
		swap(x,y);
	}
	f[y]=x;
	w[x]+=w[y];
	w[y]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++)
	{
		e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	}
	for(int i=1;i<=k;i++)
	{
		C[i]=rd();
		if(C[i]==0)
		{
			for(int j=1;j<=n;j++)
			{
				c[i][j]=rd();
				if(c[i][j]==0) now=j;
			}
			for(int j=1;j<=n;j++)
			{
				m++;
				e[m]={now,j,c[i][j]};
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		w[i]=1;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		long long u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v))
		{
			hb(u,v);
			sum+=w;
		}
	}
	cout<<sum;
}
