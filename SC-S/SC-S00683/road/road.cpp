#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
struct node{
	int u,v,w;
	bool op;
};
bool operator>(node x,node y){
	return x.w>y.w;
}
inline int read(){
	int n=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return n;
}
int fa[N],wx[15][N],sum[N];
bool f[N];
priority_queue<node,vector<node>,greater<node> >g;
bool cmp(node x,node y){
	return x.w<y.w;
}
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline bool check(int x,int y){
	x=find(x),y=find(y);
	return (x==y);
}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) fa[y]=x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int n,m,k,i,j,tot;
	n=read(),m=read(),k=read();
	tot=n;
	for(i=1;i<=m;i++){
		int u1,v1,w1;
		u1=read(),v1=read(),w1=read();
		g.push((node){u1,v1,w1,1});
	}
	bool flagt=1;
	int cnt=m,ans=0;
	for(i=1;i<=k;i++){
		int temp=read();
		if(temp>0) flagt=0;
		for(j=1;j<=n;j++){
			wx[i][j]=read();
			if(wx[i][j]>0) flagt=0;
			g.push((node){n+i,j,temp,0});
		}
	}
	if(flagt){
		cout<<"0\n";
		return 0;
	}
	for(i=1;i<=n;i++) fa[i]=i;
	while(!g.empty()){
		while(!g.empty()&&f[g.top().u-n]&&g.top().op==0) g.pop();
		if(g.empty()) break;
		int u1=g.top().u,v1=g.top().v,w1=g.top().w;
		bool opt=g.top().op;
		g.pop();
//		cout<<"*"<<u1<<","<<v1<<":"<<w1<<"\n";
		if(u1>n&&!f[u1-n]&&!opt){
//			cout<<"open"<<u1-n<<",spend"<<w1<<"\n";
			f[u1-n]=1;
			for(i=1;i<=n;i++) g.push((node){u1,i,wx[u1-n][i],1});
			ans+=w1;
		}
		else{
			if(!check(u1,v1)){
//				cout<<"merge{"<<u1<<","<<v1<<"},spend"<<w1<<"\n";
				ans+=w1;
				tot--;
				merge(u1,v1);
			}
		}
		if(tot<=1) break;
	}
	cout<<ans;
	return 0;
}