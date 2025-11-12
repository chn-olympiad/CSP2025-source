#include<bits/stdc++.h>
using namespace std;
const int N=10004;
int c[N],b,n,m,k,s[N],ans,vi[N],zh[N][N],a[N];
struct edge{
	int u,v,w;
}e[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int h(int a,int b){
	if(s[a]==s[b]) return 0;
	int y=s[b],x=s[a];
	for(int i=1;i<=n;i++){
		if(s[i]==y) s[i]=x;
	}
	return 1;
}
void aa(){
	for(int i=1;i<=n;i++) s[i]=i;
	for(int j=1;j<m;j++){
		if(h(e[j].u,e[j].v)){
			vi[j]=1;
			ans+=e[j].w;
		}
	}
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	b=m;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	aa();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=m;j++){
			if(e[j].w>a[e[j].u]+a[e[j].v]){
				ans-=e[j].w-a[e[j].u]-a[e[j].v];
				e[j].w=a[e[j].u]+a[e[j].v];
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		if(vi[i]=1) ans+=e[i].w;
//	}
	cout<<ans;
	return 0;
}

