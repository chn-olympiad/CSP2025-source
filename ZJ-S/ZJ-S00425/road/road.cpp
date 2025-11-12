//bu gua fen de hua
//yun qi cha:48pts
//yun qi hao:72pts
//yun qi yue wei 50%
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxe=5000005;
const int maxn=10005;
int g[1005][1005];
struct edge{
	int x,y,z;
	bool operator<(const edge &B)const{return z<B.z;}
}e[maxe];
int n,m,k,w,ans,a[maxn];
int fa[maxn];
int read(){
	int ret=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')ret=ret*10+(c&15),c=getchar();
	return ret;
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void adde(int x,int y,int z){e[++m]=(edge){x,y,z};}
void add_e(int x,int y,int z){
	if(n<=1000)g[x][y]=g[y][x]=min(g[x][y],z);
	else adde(x,y,z);
}
void solve(){
	w=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int id=-1;
	if(w==0){
		for(int i=1;i<=n;i++)
			if(a[i]==0){
				id=i;
				break;
			}
	}
	if(id!=-1){
		for(int i=1;i<=n;i++)if(id!=i)add_e(id,i,a[i]);
		return;
	}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		if(i!=j)add_e(i,j,a[i]+a[j]+w);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,63,sizeof g);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add_e(x,y,z);
	}
	for(int i=1;i<=k;i++)solve();
	if(n<=1000){
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(i!=j&&g[i][j]!=g[0][0])adde(i,j,g[i][j]);
	}
	sort(e+1,e+m+1);
	int cnt=n-1;
	for(int i=1;cnt;i++){
		int fx=getfa(e[i].x),fy=getfa(e[i].y);
		if(fx==fy)continue;
		fa[fy]=fx;ans+=e[i].z;cnt--;
	}
	cout<<ans;
	return 0;
}

