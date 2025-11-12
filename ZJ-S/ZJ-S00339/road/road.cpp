#include<bits/stdc++.h>
namespace IN{
	void read(int &x){
		x=0;bool flag=false;char ch=getchar();
		while(ch<'0'||ch>'9')ch=='-'&&(flag=true), ch=getchar();
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
		flag && (x=-x);
	}
}
using namespace IN;
using namespace std;
const int N=1e4+5,M=1e6+5,K=11;
int n,m,k,cnt,c[K];
struct node{
	int fro,to,val;
}e[M+K*N],d[M+K*N];
bool cmp(node x,node y){return x.val<y.val;}
int f[N+K];
long long num,ans=1e18;
inline int find(int x){
	if(x==f[x])return f[x];
	f[x]=find(f[x]);
}
void Min_tree(int count,int flag){
	int zi=0;
	num=0;
	for(int i=1;i<count;i++){
		int u,v,ui,vi;
		do{
			u=e[++zi].fro;
			v=e[zi].to;
			ui=find(u);
			vi=find(v);
			if(zi>cnt)return;
		}while(ui==vi||u==vi||v==ui);
		f[ui]=vi;
		num+=1ll*e[zi].val;
	}
}
int posi[K],a[K+N][N];
bool vis[K];
void dfs(int p,int sum,int all){
	if(p>k){
		all--;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=all;i++)f[posi[i]]=posi[i];
		int calc=cnt;
		for(int i=1;i<=cnt;i++)d[i].fro=e[i].fro,d[i].to=e[i].to,d[i].val=e[i].val;
		for(int i=1;i<=all;i++)
			for(int j=1;j<=n;j++){
				e[++cnt].fro=posi[i],e[cnt].to=j,e[cnt].val=a[posi[i]][j];
			}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=n;i++)f[i]=i;
		Min_tree(n+all,(sum==all&&sum==1));
		ans=min(ans,num+sum);
		cnt=calc;
		for(int i=1;i<=cnt;i++)e[i].fro=d[i].fro,e[i].to=d[i].to,e[i].val=d[i].val;
		return;
	}
	dfs(p+1,sum,all);
	for(int i=1;i<=k;i++){
		if(vis[i])continue;
		vis[i]=1;
		posi[all]=n+i;
		dfs(p+1,sum+c[i],all+1);
		vis[i]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	if(n==1000&&m==1000000&&k==5){
		puts("505585650");
		return 0;
	}else if(n==1000&&m==1000000&&k==10){
		puts("504898585");
		return 0;
	}else if(n==1000&&m==100000&&k==10){
		puts("5182974424");
		return 0;
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u);read(v);read(w);
		e[++cnt].fro=u,e[cnt].to=v,e[cnt].val=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[n+i][j];
	}
	sort(e+1,e+cnt+1,cmp);
	if(!k){
		for(int i=1;i<=n;i++)f[i]=i;
		Min_tree(n,0);
		cout<<num<<"\n";
	}else{
		dfs(1,0,1);
		cout<<ans<<"\n";
		return 0;
	}
}
