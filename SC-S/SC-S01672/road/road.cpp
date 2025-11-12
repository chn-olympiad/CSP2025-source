#include <bits/stdc++.h>
#define int long long
using namespace std;
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=1e4+100,M=1e6+100;
int n,m,k;
int sn;
int fa[N];
int top,topy;
bool Y[N];
int c[20];
struct node{
	int u,v,w;
	bool operator < (const node x) const{
		return w<x.w;
	}
}st[M],ts[N];
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int TREE(int n,int op){//n为当前节点数
	for(int i=1;i<=sn+k;i++)
		fa[i]=i;
	int ans=0;
	int cnt=0;
	for(int i=1;i<=top;i++){
		int x=st[i].u,y=st[i].v,w=st[i].w;
		if(x>sn && Y[x-sn]!=1) continue;
		if(find(x)==find(y)) continue;
		fa[find(x)]=find(y);
		ans+=w,cnt++;
		if(op==1) ts[++topy]={x,y,w};
		if(cnt==n-1) break;
	}
	return ans;
}
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	sn=n;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		st[++top]={u,v,w};
	}
	sort(st+1,st+top+1);
	TREE(n,1);
	
	top=0;
	for(int i=1;i<=topy;i++){
		st[++top]=ts[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			st[++top]={n+i,j,x};
		}
	}
	sort(st+1,st+top+1);
	
	int ANS=1e17;
	for(int i=0;i<(1<<k);i++){
		int ans=0;
		int nn=n;
		for(int j=1;j<=k;j++){
			Y[j]=0;
			if(((i>>(j-1))&1) == 0) continue;
			nn++,ans+=c[j];
			Y[j]=1;
		}
		ans=ans+TREE(nn,0);
		ANS=min(ANS,ans);
	}
	cout<<ANS;
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

我们可以发现k很小，考虑枚举每一个村庄建还是不建，2^10=1024
然后加入新的k*n条边后做最小生成树，但时间复杂度最大O(2^k (m+k*n))
我们可以发现在加入边之后，原来不是最小生成树的边无论如何都选不上，
考虑先做一次最小生成树，只留下n-1条边，时间复杂度O(2^k k*n)
O(1e8)
*/