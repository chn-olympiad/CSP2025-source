#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,c[N],f[N];
bool b[N];
struct sum{
	int u,v,w;
}e[N];
int gets(int x){
	if(f[x]==x)return x;
	else {
		f[x]=gets(f[x]);
		return f[x];
	}
}
bool cmp(sum x,sum y){
	return x.w<y.w;
}
void me(int x,int y){
	int tx=gets(x),ty=gets(y);
	f[tx]=ty;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			e[++m].u=i+n,e[m].v=j,e[m].w=a;
		}
	}
	int p=pow(2,k);
	sort(e+1,e+m+1,cmp);
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int num=0;num<=p;num++){
		long long sumans=0;
		for(int i=1;i<=n+k;i++)f[i]=i,b[i]=0;
		for(int i=1;i<=m;i++){
			if(e[i].u>n&& !((num>>e[i].u-n-1)&1))continue;
			int x=e[i].u,y=e[i].v;
			int tx=gets(x),ty=gets(y);
			if(tx==ty)continue;
			if(e[i].u>n&&!b[e[i].u])sumans+=c[e[i].u-n],b[e[i].u]=1;
			sumans+=e[i].w;
			me(x,y);
		}
		ans=min(ans,sumans);
	}
	cout<<ans;
	return 0;
}