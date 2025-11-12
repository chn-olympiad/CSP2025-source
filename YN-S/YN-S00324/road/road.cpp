#include <iostream>
#include <queue>
using namespace std;
const int N=1e4+25,T=1e9+5;

struct doll
{
	int be,en,val;
	int cnt;
};

struct jud
{
	operator()(doll a,doll b)
	{
		return a.val>b.val;
	}
};

int read()
{
	int num=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9')
	{
		if(a=='-') f=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		num=num*10+a-'0';
		a=getchar();
	}
	return num;
}

int n,m,k;
priority_queue<doll,vector<doll>,jud> q;
int vili[N],rode[25][N];
int a[N][N];
int c[N];
int use[25];
int find(int x)
{
	if(c[x]!=x) return c[x]=find(c[x]);
	return x;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1,u,v,w;i<=m;i++)
	{
		u=read();
		v=read();
		w=read();
		a[u][v]=w;
		q.push({u,v,w});
	}
	for(int i=1,cnt=m+1;i<=k;i++,cnt++)
	{
		vili[i]=read();

		for(int j=1;j<=n;j++)
			rode[i][j]=read();
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<j;l++)
			{
				int num=rode[i][j]+rode[i][l]+vili[i];
				if(!a[j][l]||num<a[j][l]) q.push({j,l,num,i});
			}
			c[j]=j;
		}
	}
	long long ans=0;
	while(!q.empty())
	{
		doll now=q.top();
		q.pop();
		if(find(now.be)==find(now.en)) continue;
		ans+=now.val;
		c[find(now.be)]=find(now.en);
		if(now.cnt) use[now.cnt]++;
	}
	for(int i=1;i<=k;i++){
		if(use[i]>=2) ans-=(use[i]-1)*vili[i];
	}
	cout<<ans;
	return 0;
}
