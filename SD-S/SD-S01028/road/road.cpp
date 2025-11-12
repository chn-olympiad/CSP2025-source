#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > PPI;
const int N=1e4+10,M=1e6+10,K=15,L=15;
int n,m,k;
long long ans;
bool f=1;
int c[K],a[K][N],fa[N],v[K];
PPI q[M];
bool check(int x,int y){
	int fx=x,fy=y;
	while(fa[fx]!=fx) fx=fa[x];
	while(fa[fy]!=fy) fy=fa[y];
	fa[x]=fx;fa[y]=fy;
	return fx==fy;
}
void dfs(int x){
	if(x<=k){
		v[x]=0;
		dfs(x+1);
		v[x]=1;
		dfs(x+1);
	}
	else{
		long long s=0,e=n;
		priority_queue<PPI> p;
		for(int i=1;i<=m;i++)
			p.push({-q[i].first,{q[i].second.first,q[i].second.second}});
		for(int i=1;i<=k;i++){
			if(v[i]){
				n++;
				s+=c[i];
				for(int j=1;j<=e;j++)
					p.push({-a[i][j],{n,j}});
			}
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		int cnt=0,u,v,l;
		while(cnt<n-1){
			l=-p.top().first;
			u=p.top().second.first;
			v=p.top().second.second;
			p.pop();
			if(check(u,v)) continue;
			fa[fa[v]]=fa[u];
			cnt++;
			s+=l;
		}
		ans=min(ans,s);
		n=e;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,l;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&l);
		q[i]={l,{u,v}};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		f=c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			f=a[i][j];
		}
	}
	if(!f)
		return cout<<0,0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(q+1,q+m+1);
	if(k==0){
		for(int i=1,cnt=0;cnt<n-1;i++){
			l=q[i].first;
			u=q[i].second.first;
			v=q[i].second.second;
			if(check(u,v)) continue;
			fa[v]=u;
			cnt++;
			ans+=l;
		}
		cout<<ans;
		return 0;
	}
	ans=0x3f3f3f3f3f3f3f3f;
	dfs(1);
	printf("%lld",ans);
	return 0;
}
