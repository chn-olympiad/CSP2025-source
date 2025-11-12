#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
	return ;
}
const int N=1e4+10;
int d[N],vis[N];
struct Node{
	int to,sum;
};
struct node{
	int now,sum;
};
bool operator>(node x,node y){
	return x.sum>y.sum;
}
vector<Node> a[N];
int f1[N];
int n,m,k; 
void dijkstra(int s){
	priority_queue<node,vector<node>,greater<node> >q;
	q.push({s,0});
	vis[s]=1;
	for(int i=1;i<=n;i++)	d[i]=1e18;
	d[s]=0;
	while(!q.empty()){
		node f=q.top();
		q.pop();
		for(int i=0;i<a[f.now].size();i++){
			int to=a[f.now][i].to;
			if(vis[to]==0&&f.sum+a[f.now][i].sum<d[to]){
				d[to]=f.sum+a[f.now][i].sum;
				q.push({to,d[to]});
				vis[to]=1;
			}
		}
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	bool f=0;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		a[u].push_back({v,w});
		a[v].push_back({u,w});
		if(w==0)	f=1;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		int t=read();
		if(t==0)	f=1;
		int minn=1e18;
		for(int j=1;j<=n;j++){
			int w=read();
			a[i].push_back({j,w+t});
			a[j].push_back({i,w+t});
			minn=min(minn,w);
		}
		ans+=minn;
	}
	if(f==0){
		write(ans);
		return 0;
	}
	dijkstra(1);
	cout<<d[n];
	return 0;
}

