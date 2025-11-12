#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k;
int x,y;
long long z;
vector<pair<int,long long> >v[10050];
long long c[15];
long long a[15][10050];
long long ans=1000000000000000000,sum;
struct sid{
	int x,y;
	long long w;
}s[2000050],s_[2000050];
int pnt;
int bcj[10050];
bool cmp(sid x,sid y)
{
	return x.w<y.w;
}
int cha(int x)
{
	if(bcj[x]-x) bcj[x]=cha(bcj[x]);
	return bcj[x];
}
int bing(int x,int y)
{
	//cerr<<x<<' '<<y<<'\n';
	x=cha(x),y=cha(y);
	//cerr<<x<<' '<<y<<'\n';
	if(x==y) return 0;
	bcj[x]=y;
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		v[x].push_back(make_pair(y,z));
		v[y].push_back(make_pair(x,z));
		s_[i].x=x,s_[i].y=y,s_[i].w=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++)
	{
		//cerr<<i<<':'<<'\n';
		sum=0;
		pnt=m;
		for(int j=1;j<=m;j++) s[j]=s_[j];
		for(int j=1;j<=n+k;j++) bcj[j]=j;
		for(int p=0;p<k;p++)
		{
			if(i&(1<<p))
			{
				sum+=c[p+1];
				for(int j=1;j<=n;j++)
				{
					pnt++;
					s[pnt].x=n+p+1,s[pnt].y=j,s[pnt].w=a[p+1][j];
				}
			}
		}
		sort(s+1,s+pnt+1,cmp);
		for(int j=1;j<=pnt;j++)
		{
			long long t=s[j].w*bing(s[j].x,s[j].y);
			sum+=t;
			//cerr<<t<<'\n';
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
