#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	int to,next,w;
}a[N];
int pre[N],k;
int ma[N];
bool inst[N];
void add(int u,int v,int w){
	a[++k]={v,pre[u],w};
	pre[u]=k;
}
queue<int> q;
void spfa(int x){
	ma[1]=0;
	for(int i=pre[x];i;i=a[i].next){
		int to=a[i].to;
		if(ma[x]+a[to].w<ma[to]){
			ma[to]=ma[x]+a[to].w;
			spfa(to);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	memset(ma,0x3f,sizeof(ma));
	for(int i=1;i<=n;i++){
		spfa(i);
	}
	int w[N],k1=0;
	for(int i=1;i<=k1;i++){
		cin>>w[++k1];
		m++;
		for(int i=1;i<=n-1;i++){
			int x;
			cin>>x;
			add(m,i,x);
			add(i,m,x);
		}
	}
	for(int i=1;i<=n+m;i++){
		spfa(i);
		cout<<ma[i]<<endl;
	}
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
