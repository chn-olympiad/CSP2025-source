#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int N=2000006;

int n,m,k;
struct bian{
	int u,v,w;
}a[N],edge[N],b[N];
int tot=0;
bool cmp(bian a,bian b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool vis[20];
int g[20][N],c[20];
int ans=0;

void check(){
	for(int i=1;i<=tot;i++) b[i]=edge[i];
	int cnt=tot;
	int res=0;
	int dian=n;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			res+=c[i];
			dian++;
			for(int j=1;j<=n;j++){
				b[++cnt].u=dian;
				b[cnt].v=j;
				b[cnt].w=g[i][j];
			}
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=dian;i++) fa[i]=i;
	int sum=0;
	for(int i=1;i<=cnt;i++){
		int u=b[i].u,v=b[i].v,w=b[i].w;
		u=find(u),v=find(v);
		if(u==v) continue;
		fa[u]=v;
		res+=w;
		sum++;
		if(sum==dian-1) break;
	}
	ans=min(ans,res);
	return;
}

void dfs(int nowat){
	if(nowat==k+1){
		check();
//		cout<<ans<<endl;
		return;
	}
	vis[nowat]=0;
	dfs(nowat+1);
	vis[nowat]=1;
	dfs(nowat+1);
	return;
}

bool Mbe;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road4.in","r",stdin);
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		u=find(u),v=find(v);
		if(u==v) continue;
		fa[u]=v;
		edge[++tot]=a[i];
		ans+=w;
		if(tot==n-1) break;
	}
//	cout<<"ANS "<<ans<<endl;
//	for(int i=1;i<=tot;i++){
//		cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<endl;
//	}

	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			g[i][j]=read();
		}
	}
	
	dfs(1);
	cout<<ans<<endl;
	
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

特殊性质A应该是
让我把a[j][i]为0的那个位置 中的 一条边 替换为 c[j]
对

是不是可以证明
只需要保留 n-1 条边
也就是第一次kruskal出来的那个树
然后
再 2^10 枚举一下就行了

感觉可能可以
等我思考一下有没有反例
 
好像可以 不难写 写一下 

*/
