#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m,k;
struct edge{
	int u,v;
	long long w;
};
edge e[2000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int f[10015];
int ff(int x){
	if(f[x]==x) return x;
	f[x]=ff(f[x]);
	return f[x];
}
long long a[15][10005];
int flag[15];
long long mst1(){
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=ff(e[i].u),fy=ff(e[i].v);
		if(fx!=fy){
			f[fx]=fy;
			cnt++;
			e[cnt].u=e[i].u,e[cnt].v=e[i].v,e[cnt].w=e[i].w;
			ans+=e[cnt].w;
		}
		if(cnt==n-1) return ans;
	}
	return ans;
}
long long mst2(){
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=ff(e[i].u),fy=ff(e[i].v);
		if(fx!=fy){
			f[fx]=fy;
			ans+=e[i].w;
		}
		if(cnt==n-1) return ans;
	}
	return ans;
}
void solvea(){
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			if(j!=flag[i]){
				m++;
				e[m].u=j,e[m].v=flag[i],e[m].w=a[i][j];
			}
	sort(e+1,e+m+1,cmp);
	printf("%lld",mst2());
	return;
}
set<int> ok[15];
edge ed[1000005];
long long mst3(){
	long long ans=0;
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		if(ed[i].u<ed[i].v) swap(ed[i].u,ed[i].v);
		int fx=ff(ed[i].u),fy=ff(ed[i].v);
		if(fx!=fy){
			f[fx]=fy;
			ans+=ed[i].w;
		}
		else if(ed[i].u>n) ok[ed[i].u-n].erase(ed[i].v);
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++){
			a[i][j]=read();
			if(!a[i][j]) flag[i]=j;
		}
//	bool A=1; ·ÅÊÖÒ»²«°É£¡ 
//	for(int i=1;i<=k;i++)
//		if(a[i][0]||!flag[i]) A=0;
//	if(A){
//		solvea();
//		return 0;
//	}
	sort(e+1,e+m+1,cmp);
	long long ans=mst1();
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			ok[i].insert(j);
	for(int i=1;i<(1<<k);i++){
		m=n-1;
		for(int j=1;j<n;j++)
			ed[j]=e[j];
		int x=i;
		long long aans=0;
		for(int j=1;j<=k;j++){
			if(x&1){
				aans+=a[j][0];
				for(int p:ok[j]){
					m++;
					ed[m].u=j+n,ed[m].v=p,ed[m].w=a[j][p];
				}
			}
			x>>=1;
		}
		sort(ed+1,ed+m+1,cmp);
		ans=min(ans,mst3()+aans);
	}
	printf("%lld",ans);
	return 0;
}
