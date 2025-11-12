#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const int M=2e6+5;
int n,m,cnt;
vector<int> q[N];
vector<int> v[N];
int k,uu,vv,ww;
int a[15][N];
//------------------
struct D
{
	int u,v,w;
}b[M],ttt;
int f[N];
int fa(int x)
{
	//if(x>2*n)return 0;
	if(f[x]==x)return x;
	f[x]=fa(f[x]);
	return f[x];
}
bool cmp(D qw1,D qw2)
{
	return qw1.w<qw2.w;
}
long long ans;
void goo()
{
	ans=0;
	for(int i=1;i<=2*n;i++)f[i]=i;
	sort(b+1,b+cnt+1,cmp);
	
	for(int i=1;i<=cnt;i++)
	{
		if(fa(b[i].u)!=fa(b[i].v))
		{
			f[fa(b[i].v)]=fa(b[i].u);
			ans+=b[i].w;
		}
		//return;
	}
	
}
//------------------
int main()
{
	bool asa=1;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>uu>>vv>>ww;
		q[uu].push_back(vv);
		q[vv].push_back(uu);
		v[uu].push_back(ww);
		v[vv].push_back(ww);
		b[i].u=uu;
		b[i].v=vv;
		b[i].w=ww;
	}
	for(int i=1;i<=k;i++)
	{
		
		for(int j=0;j<=n;j++)cin>>a[i][j];
		if(a[i][0]!=0)asa=0;
	}
	
	cnt=m;
	if(asa)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				q[j].push_back(i+n);
				q[i+n].push_back(j);
				v[j].push_back(a[i][j]);
				v[i+n].push_back(a[i][j]);
				b[++cnt].u=i+n;
				b[cnt].v=j;
				b[cnt].w=a[i][j];
			}
		}
		goo();
		cout<<ans;
		return 0;
	}
	cout<<cnt;
	goo();
	cout<<ans;
	
	return 0;
}
