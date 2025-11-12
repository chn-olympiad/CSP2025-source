#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,inf=1e18,mod=1e9+7;
int read(){
	int x;
	scanf("%lld",&x);
	return x;
}
void write(int x){
	printf("%lld",x);
}
void writeh(int x){
	printf("%lld",x);
	putchar('\n');
}
void writek(int x){
	printf("%lld",x);
	putchar(' ');
}
int T,n,v[N][3],ans;
void dfs(int pos,int a,int b,int c,int sum){
	if(a>n/2 || b>n/2 || c>n/2) return ;
	if(pos==n+1){
		ans=max(ans,sum);
		return ;
	}
	dfs(pos+1,a+1,b,c,sum+v[pos][0]);
	dfs(pos+1,a,b+1,c,sum+v[pos][1]);
	dfs(pos+1,a,b,c+1,sum+v[pos][2]);
}
int fv[N]; bool flag1;
bool cmp(int x,int y){
	return x>y;
}
int t[3],tot,val[N][3],cnt; bool vis[N];
struct node{
	int id,v,p;
};
node a[N];
void init(){
	ans=0; tot=0; cnt=0;
	for(int i=1;i<=3;i++) t[i]=0;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
}
bool cmp1(node x,node y){
	return x.v>y.v;
}
struct qnode{
	int id,v;
	friend bool operator < (qnode x,qnode y){
		return x.v>y.v;
	}
};
void solve(){
	priority_queue <qnode> q[3];
	init();
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			int x=read();
			a[++tot]=(node){i,x,j};
			val[i][j]=x;
		}
	}
	sort(a+1,a+tot+1,cmp1);
	for(int i=1;i<=tot;i++){
		if(cnt==n) break;
		int id=a[i].id,p=a[i].p,v=a[i].v;
		if(vis[id]) continue;//人已被访问
		if(t[p]+1>n/2){
			int s1=0,s2=0;//剩余两个组织编号
			for(int i=0;i<3;i++){
				if(i!=p){
					if(!s1) s1=i;
					if(!s2) s2=i;
				}
			}
			//是否替换q[p].top().id
			int u=q[p].top().id;
			if(val[u][s1]<val[u][s2]) swap(s1,s2);//记录最大
			if(v+val[u][s1]>val[u][p]){//替换
				t[s1]++;
				q[s1].push((qnode){u,val[u][s1]});
				q[p].pop();
				q[p].push((qnode){id,v});
				vis[id]=1;
				cnt++;
				ans+=v+val[u][s1]-val[u][p];
			}
			continue;
		}
		cnt++;
		vis[id]=1;
		t[p]++;
		q[p].push((qnode){id,v});
		ans+=v;
	}
	writeh(ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				v[i][j]=read();
				if(j && v[i][j]) flag1=1;
			}
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			writeh(ans);
			continue;
		}
		if(!flag1){
			memset(fv,0,sizeof(fv));
			for(int i=1;i<=n;i++) fv[i]=v[i][0];
			sort(fv+1,fv+n+1,cmp);
			int tmp=0;
			for(int i=1;i<=n/2;i++) tmp+=fv[i];
			writeh(tmp);
			continue;
		}
		solve();
	}
	return 0;
}