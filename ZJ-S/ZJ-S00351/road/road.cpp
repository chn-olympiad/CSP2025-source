#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fre {freopen("road.in","r",stdin);freopen("road.out","w",stdout);}
#define pii pair<LL,LL>
#define mp make_pair
LL n,m,k,fa[10050],kw[15][10500],vis[15],kww[15],ned[15],sum,ct,ans=1e17,tt;
struct edge{
	LL u,v,w;
	bool operator <(const edge &x)const{
		return x.w<w;
	}
}e[1205000],ee[1205000];
LL find(LL x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
priority_queue<edge> q;
void kur(LL x)
{
	LL cnt=0;
	while(!q.empty())
	{
		LL uu=q.top().u,vv=q.top().v,ww=q.top().w;q.pop();
		LL fu=find(uu),fv=find(vv);
		if(fu!=fv)
		{
			fa[fu]=fv,++cnt,sum+=ww;
			if(x==0) ee[cnt]={uu,vv,ww};
			if(cnt==n+x-1) return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	fre;
	//freopen("road4.in","r",stdin);
	cin>>n>>m>>k;
	for(LL i=1;i<=n+k;++i) fa[i]=i;
	for(LL u,v,w,i=1;i<=m;++i)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(LL i=1;i<=m;++i) q.push(e[i]);
	kur(0);
	if(!k)
	{	cout<<sum<<endl;
		return 0;
	}
	LL cnnt=n-1;
	LL fg=0;
	ans=sum;
	sum=0;
	while(!q.empty()) q.pop();
	for(LL i=1;i<=k;++i)
	{
		cin>>kww[i];
		if(kww[i]>0) fg=1;
		for(LL j=1;j<=n;++j)
			cin>>kw[i][j];	
		if(kww[i]==0)
			for(LL j=1;j<=n;++j) ee[++cnnt]=edge{n+i,j,kw[i][j]};
	}
	if(!fg){for(LL i=1;i<=cnnt;++i) q.push(ee[i]);for(LL i=1;i<=n+k;++i) fa[i]=i;kur(k);cout<<sum<<endl;return 0;}
	cnnt=n-1;
	for(LL i=1;i<(1<<k);++i)
	{
		sum=0;
		for(LL i=1;i<=n+k;++i) fa[i]=i;
		while(!q.empty()) q.pop();
		for(LL j=1;j<=cnnt;++j) q.push(ee[j]);
		LL tj=0;
		for(LL j=1;j<=k;++j) 
		{
			if((1<<(j-1))&i)
			{
				++tj;
				for(LL l=1;l<=n;++l) q.push(edge{n+j,l,kw[j][l]});
				sum+=kww[j];
			}
		}
		kur(tj);
		ans=min(sum,ans);
	}
	cout<<ans<<endl;
	return 0;
}
