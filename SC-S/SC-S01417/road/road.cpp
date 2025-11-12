#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long n,m,k,fa[2000010],c[2000010],co[15][2000010],pos[20],cnt=0,sum;
long long find(long long x){
	if(x==fa[x])return fa[x];
	else return fa[x]=find(fa[x]);
}
struct edge{
	long long l,r,w;
}e[2000010];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
signed main(){
	ios
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(long long i=1;i<=m;i++)cin>>e[i].l>>e[i].r>>e[i].w;
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++)cin>>co[i][j];
		for(int j=1;j<=n;j++){
			if(!co[i][j]){
				pos[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j==pos[i])continue;
			e[++m].l=pos[i],e[m].r=j;
			e[m].w=co[i][j];
		} 
	}
	sort(e+1,e+m+1,cmp);
	for(long long i=1;i<=m;i++){
		long long e1=e[i].l,e2=e[i].r;
		e1=find(e1),e2=find(e2);
		if(e1!=e2){
			++cnt;
			sum+=e[i].w;
			fa[e2]=e1;
		}
		if(k==n-1){
			break;
		}
	}
	cout<<sum;
	return 0;
}