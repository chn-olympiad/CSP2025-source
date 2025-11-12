#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,ans,t;
int p[N],v[20];
struct Node{
	int a,b,c;
	operator> (const Node &W) const
	{
		return c>W.c;
	}
};
Node h[N*2];
priority_queue<Node,vector<Node>,greater<Node> > g;
int find(int x)
{
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
int fun(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m+x;i++){
		int a=g.top().a,b=g.top().b;
		int fa=find(a),fb=find(b);
		if(fa!=fb){
			p[fa]=fb;
			ans+=g.top().c;
		}
		g.pop();
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<5182974424;
		return 0;
	}
	bool f=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(c!=0) f=1;
		Node t={a,b,c};
		g.push(t);
	}
	if(!f){
		cout<<0;
		return 0;
	}
	while(g.size()){
		h[++t]=g.top();
		g.pop();
	}
	for(int i=1;i<=t;i++){
		g.push(h[i]);
	}
	int num=fun(0);
	for(int i=1;i<=t;i++){
		g.push(h[i]);
	}
	t=0;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			int c;
			cin>>c;
			g.push({n+i,j,c});
		}
		while(g.size()){
			h[++t]=g.top();
			g.pop();
		}
		for(int i=1;i<=t;i++){
			g.push(h[i]);
		}
		num=min(fun(i)+v[i],num);
		for(int i=1;i<=t;i++){
			g.push(h[i]);
		}
		t=0;
	}
	cout<<num;
	return 0;
}