#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
template<typename type>
inline void read(type &x){
	x=0;
	static bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		flag=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}
struct node{
	int id,cnt,vip;
};
int n,m,k;
int f[N][N];
bool vis[N][N];
node a[N];
int ans;
queue<node> q;
void bfs(){
	q.push(a[1]);
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(now.vip==n){
			ans=now.cnt;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(f[now.id][i]&&!vis[now.id][i]){
				node nnow=now;
				nnow.vip++;
				nnow.cnt+=f[now.id][i];
				vis[now.id][i]=1;
				q.push(nnow);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u),read(v),read(w);
		f[u][v]=f[v][u]=w;
		a[i].id=i,a[i].cnt=0,a[i].vip=1;
	}
	for(int i=1;i<=k;i++){
		int c,a;
		read(c);
		for(int i=1;i<=n;i++){
			read(a);
		}
	}
	bfs();
	printf("%d",ans);
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
//			}
//		}
//	}
	return 0;
}

