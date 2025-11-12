#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int n,f[2][5010][5010];
int g[2][M],ans;
struct NODE
{
	int x,y,z;
}a[M],b[M];
bool sgA=true,sgB=true;
double T0;

bool cmpA(NODE a,NODE b)
{
	return a.x>b.x;
}

void workA()
{
	sort(a+1,a+n+1,cmpA);
	int res=0;
	for(int i=1;i<=n/2;i++)
		res+=a[i].x;
	printf("%lld\n",res);
	return;
}

void workB()
{
	for(int i=0;i<2;i++)
		for(int j=0;j<=n/2;j++)
			g[i][j]=0;
	g[1][1]=a[1].x,g[1][0]=a[1].y;
	int cur=1;
	for(int i=2;i<=n;i++)
	{
		cur^=1;
		for(int j=0;j<=n/2;j++)
			if(i-j>=0&&i-j<=n/2)
			{
				if(j>=1)   g[cur][j]=max(g[cur][j],g[cur^1][j-1]+a[i].x);
				if(i-j>=1) g[cur][j]=max(g[cur][j],g[cur^1][j]+a[i].y);
			}
	}
	ans=0;
	for(int i=0;i<=n/2;i++)
		if(n-i<=n/2)
			ans=max(ans,g[cur][i]);
	printf("%lld\n",ans);
	return;
}

void SA()
{
	double Tb=30000,Te=1e-10,delta=0.911;
	while(Tb-Te>1e-15)
	{
		Tb*=delta;
		int x=rand()%(n/2+1),y=rand()%(n/2+1);
		swap(b[x],b[y]);
		if(n-x-y>n/2) continue;
		int res=0;
		for(int i=1;i<=x;i++)     res+=b[i].x;
		for(int i=x+1;i<=x+y;i++) res+=b[i].y;
		for(int i=x+y+1;i<=n;i++) res+=b[i].z;
		if(res>ans) ans=res;
		else if((res-ans)/(Tb-Te)<rand()/INT_MAX)
			swap(b[x],b[y]);
	}
}

void work()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].y||a[i].z) sgA=false;
		if(a[i].z) sgB=false;
	}
	
	if(sgA)
	{
		workA();
		return;
	}
	if(sgB)
	{
		workB();
		return;
	}
	if(n<=1e4)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++)
					f[i][j][k]=0;
		f[1][1][0]=a[1].x,f[1][0][1]=a[1].y,f[1][0][0]=a[1].z;
		int cur=1;
		for(int i=2;i<=n;i++)
		{
			cur^=1;
			for(int j=0;j*2<=n;j++)
				for(int k=0;k*2<=n&&i-j-k>=0;k++)
					if((i-j-k)*2<=n)
					{
						if(j>=1)     f[cur][j][k]=max(f[cur][j][k],f[cur^1][j-1][k]+a[i].x);
						if(k>=1)     f[cur][j][k]=max(f[cur][j][k],f[cur^1][j][k-1]+a[i].y);
						if(i-j-k>=1) f[cur][j][k]=max(f[cur][j][k],f[cur^1][j][k]+a[i].z);
					}
		}
			
		ans=0;
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++)
				if(n-i-j>=0&&n-i-j<=n/2)
					ans=max(ans,f[cur][i][j]);
		printf("%lld\n",ans);
		return;
	}
	
	srand(time(0));
	ans=0;
	int TT=5;
	while(TT--)
	{
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		SA();
	}
	printf("%lld\n",ans);
	
	return;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		work();
	
	return 0;
}