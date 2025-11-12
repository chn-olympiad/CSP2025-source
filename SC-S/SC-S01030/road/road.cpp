#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k,ans;
struct node{
	int u,v,w;
	bool operator<(const node B)const{
		return w<B.w;
	}
	bool operator>(const node B)const{
		return w>B.w;
	}
};
priority_queue<node,vector<node>,greater<node> >q1;
priority_queue<node>q2;
int f[N],c[15],a[15][N];
int find(int x){
	if(x==f[x])return f[x];
	return f[x]=find(f[x]);
}
bool check(){
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		q1.push({x,y,z});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	while(!q1.empty()){
		node z=q1.top();q1.pop();
		int x=find(z.u),y=find(z.v);
		if(x!=y){
			f[x]=y;
			ans+=z.w;
			q2.push(z);
		}
	}
	cout<<ans;
	return 0;
}
/*
奇妙的最小生成树。
14:59先在原图上跑一遍最小生成树，这样不会劣。
接着对于每条边看能不能用乡镇k优化。
15:15城市化只需要一次，麻烦，看看后面。
18:07特殊性质也不会，16pts。
*/