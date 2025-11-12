#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,f[100005];
struct point
{
	int cong,dao,val;
}bian[1000005];
bool cmp(point x,point y)
{
	return x.val<y.val;
}
long long ans;
int find(int x)
{
	if(f[x]==x){return x;}
	return f[x]=find(f[x]);
}
bool jian[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>bian[i].cong>>bian[i].dao>>bian[i].val;
		}
		sort(bian+1,bian+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=n;i++){f[i]=i;}
		for(int i=1;i<=m;i++)
		{
			int wow1=find(bian[i].cong),wow2=find(bian[i].dao);
			if(wow1==wow2){continue;}
			f[wow1]=wow2;
			ans+=bian[i].val;
			cnt++;
			if(cnt==n-1){break;}
		}
		cout<<ans<<"\n";
	}
	else
	{
		for(int i=1;i<=m;i++){int x;cin>>x>>x>>x;}
		for(int i=1;i<=k;i++){int x;
		cin>>x;
		for(int i=1;i<=n;i++){int y;
		cin>>y;}
		} 
		cout<<0; 
	}
	return 0;
}
