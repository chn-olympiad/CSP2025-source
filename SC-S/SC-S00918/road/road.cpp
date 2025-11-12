#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,len,all;
struct node{
	int x,y,si;
};vector<node>g,g1;
int fa[11451];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.si<b.si;
}
int kul(){
	len=0;int kk=0;
	sort(g1.begin(),g1.end(),cmp);
	for(node c:g1){
		int x=c.x,y=c.y,val=c.si;
		int d=find(x),e=find(y);
		if(d==e)continue;
		kk++;
		fa[d]=e;
		len+=val;if(kk==len-1)return len;
	}
	return len;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	all=n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,val;
		cin>>x>>y>>val;
		g.push_back({x,y,val});
		g1.push_back({x,y,val});
	}int ans=kul();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+i;j++)fa[j]=j;
		int num;
		cin>>num;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			g1.push_back({n+i,j,x});
		}int y=kul();
		if(y+num<ans){
			g=g1;
			ans=y+num;all++;
			
		}
	}
	cout<<ans;
	return 0;
}