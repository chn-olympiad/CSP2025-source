#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
int n,m,k,a,b,c,xz[15],lt[15][10005],fa[10025],zz[15];
long long ans=LLONG_MAX;
vector<node> r;
bool cmp(node x,node y){
	if(x.w==y.w){
		if(y.u>n&&x.u>n) return zz[x.u]>zz[y.u];
		if(y.u>n) return 0;
		if(x.u>n) return 0;
	}
	return x.w<y.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void kursker(int cz,int e){
	for(int i=1;i<=n+e;i++) fa[i]=i;
	vector<node> ls;
	for(int i=0;i<r.size();i++) ls.push_back(r[i]);
	sort(ls.begin(),ls.end(),cmp);
	long long sum=cz,cnt=1;
	for(int i=0;i<ls.size();i++){
		int xx=find(ls[i].u),yy=find(ls[i].v);
		if(xx==yy) continue;
		cnt++;
		sum+=ls[i].w;
		if(sum>ans) return;
		fa[ls[i].u]=ls[i].v;
		if(cnt==n+e) break;
	}
	ans=min(ans,sum);
	return;
}
void dfs(int i,int sum,int chose){
	if(sum>ans) return;
	if(i>k){
		kursker(sum,chose);
		return;
	}
	dfs(i+1,sum,chose);
	for(int j=1;j<=n;j++) r.push_back({n+chose+1,j,lt[i][j]});
	dfs(i+1,sum+xz[i],chose+1);
	for(int j=1;j<=n;j++) r.pop_back();
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool tsa=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		r.push_back({a,b,c});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&xz[i]);
		if(xz[i]!=0) tsa=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&lt[i][j]);
			zz[i]+=lt[i][j];
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(r.begin(),r.end(),cmp);
		long long cnt=1;
		for(int i=0;i<r.size();i++){
			int xx=find(r[i].u),yy=find(r[i].v);
			if(xx==yy) continue;
			cnt++;
			ans+=r[i].w;
			fa[xx]=yy;
			if(cnt==n) break;
		}
	}else if(tsa){
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=k;i++){
			int sfd;
			for(int j=1;j<=n;j++) if(lt[i][j]==0){sfd=j;break;}
			for(int j=1;j<=n;j++) r.push_back({sfd,j,lt[i][j]});
		}
		sort(r.begin(),r.end(),cmp);
		long long cnt=1;
		for(int i=0;i<r.size();i++){
			int xx=find(r[i].u),yy=find(r[i].v);
			if(xx==yy) continue;
			cnt++;
			ans+=r[i].w;
			fa[xx]=yy;
			if(cnt==n) break;
		}
	}else dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
