#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,val;
};
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
vector<node>e,we;
int n,m,k,u,v,w,ans=1e9,us[11],base,fa[10100];
int c[11],a[11][10010];
bool cmp(node uu,node ii){
	return uu.val<ii.val;
}
int fat(int x){
	if(fa[x]==x)return x;
	else return fa[x]=fat(fa[x]);
}
void work(){
//	cout<<we.size();
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	sort(we.begin(),we.end(),cmp);
//	cout<<1;
	int Base=base;
	for(int i=0;i<we.size();i++){
//		cout<<1;
		node uo=we[i];
		int fx=fat(uo.x);
		int fy=fat(uo.y);
		if(fx!=fy){
			fa[fx]=fy;
			Base+=uo.val;
		}
		if(Base>=ans)return;
	}ans=Base;
//	cout<<1;
	return;
}
void dfs(int x){
	if(x==k+1){
//		cout<<1;
		we=e;
//		we.clear();
//		for(int i=0;i<e.size();i++)
//			we.push_back(e[i]);
		for(int i=1;i<=k;i++){
			if(us[i]){
				for(int j=1;j<=n;j++)
					we.push_back({i+n,j,a[i][j]});
			}
		}
		work();
		return;
	}
	if(c[x]!=0)dfs(x+1);
	us[x]=1;
	base+=c[x];
	dfs(x+1);
	us[x]=0;
	base-=c[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	dfs(1);
	cout<<ans;
}