#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long c[15];
long long a[15][10005];
bool vis[15][10005],use[100005];
int I;
long long find_mn(int j){
	long long mn=0x7fffffff;
	for(int i=1;i<=n;++i){
		if(!vis[j][i]) mn=min(mn,a[j][i]);
		if(mn=a[j][i]) I=i;
	}
	return mn;
}
struct node {
	int u,v;
	int w;
}e[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int nod[15];
int fa[10005];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i){
		int r1=find(e[i].u),r2=find(e[i].v);
		if(r1!=r2){
			fa[r1]=fa[r2];
			ans+=e[i].w;
			use[i]=1;
		}
	}
	if(!k){cout<<ans;return 0;}
	for(int j=1;j<=k;++j){
		bool flag=0;
		for(int i=m;i>=1;--i){
			if(!use[i]) continue;
			int U=e[i].u,V=e[i].v;
			int tmp=min(a[j][U],a[j][V]);
			int idx=0;
			if(tmp==a[j][U]) idx=U;
			else idx=V;
			if(nod[j]==0){
				tmp+=c[j];
				vis[j][idx]=1;
				tmp+=find(j);
				vis[j][I]=1;
				nod[j]++;
			}
			if(e[i].w>tmp){
				ans-=e[i].w;
				ans+=tmp;
				e[i].w=tmp;
				nod[j]=(nod[j]?nod[j]+1:2);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
