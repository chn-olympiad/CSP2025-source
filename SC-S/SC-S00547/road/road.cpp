#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct side{
	int x,y,w,is;
}a[1100005];



int c[15];
int f[10015];

int n,m,k;
long long ans;
bool cmp(side x,side y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
		
	}
	
		
	
		sort(a+1,a+m+1,cmp);
		int j=1;
		for(int i=1;i<n;i++)
		{
			for(;j<=m;j++)
			{
				if(find(a[j].x)!=find(a[j].y))
				{
					f[a[j].x]=find(f[a[j].y]);
					ans+=a[j].w;
					break;
				}
			}
		
		}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int p;
			scanf("%d",&p);
			a[++m]={j,n+i,p};
		}
			
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	sort(a+1,a+m+1,cmp);
	j=1;
	long long ans1=0;
	//int need=n;
	for(int i=1;i<n+k;i++)
	{
		for(;j<=m;j++)
		{
			
			if(find(a[j].x)!=find(a[j].y))
			{
				f[a[j].x]=find(f[a[j].y]);
				if(f[a[j].y>n])ans1+=c[a[j].y];
				ans1+=a[j].w;
				break;
			}
		}
		
	}
	cout<<min(ans,ans1);
	return 0;
}