#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e4+13,MAXM=1e6+3,INF=0x3f3f3f3f3f3f3f3f;
inline ll read(){
	ll x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,k;
struct node{
	int u,v,w;
};
vector<node> ed;
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[MAXN],siz[MAXN];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
}
int find(int k){
	return fa[k]=k?k:fa[k]=find(fa[k]);
}
void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(siz[x]>siz[y]) swap(x,y);
	siz[y]+=siz[x];
	fa[x]=y;
}
bool query(int x,int y){
	return find(x)!=find(y);
}
int kruskal(){
	int ans=0,cnt=0;
	sort(ed.begin(),ed.end(),cmp);
	for(auto it:ed){
		int u=it.u,v=it.v,w=it.w;
		if(query(u,v)){
			ans+=w;
			cnt++;
			unite(u,v);
		}
		if(cnt==n-1) break;
	}
	return ans;
}
int c[13],d[13];
vector<int> a[13];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		ed.push_back({u,v,w});
	}
	if(k==0){
		cout<<kruskal();
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0) flag=0;
		for(int j=0;j<n;j++){
			a[i].push_back(read());
			if(a[i][j]==0) d[i]=j+1;
		}
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]!=0) ed.push_back({d[i],j+1,a[i][j]});
			}
		}
		cout<<kruskal();
		return 0;
	}
	return 0;
}


