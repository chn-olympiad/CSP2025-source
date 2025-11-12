#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct str{
	int v,w;
}d[M];
vector<str> a[N];
int n,m,k,x,y,z,fa[N],ans,cnt;
bool cmp(str x,str y){
	return a[x.v][x.w].w<a[y.v][y.w].w;
}
int bc(int x){
	if(fa[x]==fa[fa[x]])return fa[x];
	else return fa[x]=bc(fa[x]); 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
		d[++cnt]={x,int(a[x].size())-1};
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>z;
			a[i].push_back({j,z});
			a[j].push_back({i,z});
			d[++cnt]={i,int(a[i].size())-1};
		}
	}
	m+=k*n;
	sort(d+1,d+cnt+1,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(bc(d[i].v)!=bc(a[d[i].v][d[i].w].v))fa[fa[d[i].v]]=bc(fa[a[d[i].v][d[i].w].v]),ans+=a[d[i].v][d[i].w].w;//cerr<<d[i].v<<' '<<a[d[i].v][d[i].w].v<<'\n';
//		for(int i=1;i<=n+k;i++)cerr<<fa[i]<<' ';
//		cerr<<'\n';
	}	
	cout<<ans<<endl;
//	cerr<<clock();
}
//发现乡镇较少，一个显然正确的O(mlogm*2^k)做法
//优化：先跑最小生成树，然后把树上的乡镇拆掉
//此时，如果拆掉路径上的乡镇，则先拆掉再跑最小生成树 
//理论可达O(kmlogm)
//接下来是并不愉快的代码时间
//不开ll见祖宗…… 
//fa xian ling yi zhong fang fa
//yi ge xiang zhen yao shi you yong,jiu yi ding ke yi qu dai yi xie zhi qian de bian
//mei shi jian le
//wo jiu xie ge k==0 ba
//xin zhi a,ye ke yi xie
