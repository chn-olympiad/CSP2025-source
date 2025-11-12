#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0;
	char p=getchar();
	while(p<'0'||p>'9'){
		p=getchar();
	}
	while(p>='0'&&p<='9'){
		s*=10;
		s+=p-'0';
		p=getchar();	
	}
	return s;
}
int fa[10055],n,m,k,ans,now,cnt,vis[15],a[15][10005],c[15];
struct node{
	int a,b,c;	
}p[10055];
bool operator >(node a,node b){
	return a.c>b.c;	
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);	
}
priority_queue<node,vector<node>,greater<node> >q;
void check(){
	int tmp=now;
	for(int i=1;i<=cnt;++i){
		q.push(p[i]);	
	}
	int num=n;
	for(int i=1;i<=k;++i){
		if(vis[i]){
			++num;
			for(int j=1;j<=n;++j){
				q.push({num,j,a[i][j]});
			}
		}
	}
	for(int i=1;i<=num;++i) fa[i]=i;
	while(!q.empty()){
		node x=q.top();
		q.pop();
		int a=find(x.a),b=find(x.b);
		if(a==b) continue ;
		else{
			fa[a]=fa[b];
			tmp+=x.c;
		}
	}
	ans=min(ans,tmp);
}
void dfs(int x){
	if(now>=ans) return ;
	if(x==k+1){
		check();
		return ;
	}
	vis[x]=1;
	now+=c[x];
	dfs(x+1);
	vis[x]=0;
	now-=c[x];
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),z=read();
		q.push({x,y,z});	
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	while(!q.empty()){
		node x=q.top();
		q.pop();
		int a=find(x.a),b=find(x.b);
		if(a==b) continue ;
		else{
			p[++cnt]=x;
			fa[a]=fa[b];
			ans+=x.c;
		}
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j) a[i][j]=read();	
	}
//	for(int s=1;s<(1<<k);++s){
//		now=0;
//		for(int i=0;i<k;++i){
//			if((s>>i)&1){
//				vis[i+1]=1;
//				now+=c[i+1];	
//			}
//		}
//		if(now>=ans) continue ;
//		check();
//	}
	dfs(1);
	cout<<ans;
	return 0;
}

