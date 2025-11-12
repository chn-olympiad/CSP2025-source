#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int N=2e6+5,mod=1e9+7;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int head[N],End[N],Next[N],tot=-1,edge[N];
void add(int x,int y,int z){
	Next[++tot]=head[x];
	head[x]=tot;
	End[tot]=y;
	edge[tot]=z;
}
int n,m,k,v[N],dist[N],ans=1e18,ans1;
void dfs(int x){
	v[x]=1;
	for(int i=head[x];~i;i=Next[i]){
		int y=End[i],z=edge[i];
		if(v[y])continue;
		dist[y]=dist[x]+z;
		dfs(y);
		ans1+=z;
	}
	return;
}
int sum;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof head);
	memset(dist,-1,sizeof dist);
	n=read(),m=read(),k=read();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		sum=0;
		for(int j=1;j<=n+1;j++){
			x=read();
			sum+=x;
		} 
		ans=min(sum,ans);
	}
	for(int i=1;i<=n;i++){
		ans1=0;
		dfs(i);
		for(int i=1;i<=n;i++)v[i]=0;
		ans=min(ans,ans1);
	}
	cout<<ans<<endl;
	return 0;
}


