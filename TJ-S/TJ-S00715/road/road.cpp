#include<bits/stdc++.h>
using namespace std;

int n,m,k,cnt;//n=城市数量，m=道路数量，k=乡镇数量 
int c[10005];

struct node1{//道路 
	int u,v,w;//连接 u,v 两座城市，修复费为 W 
}; 
node1 a[10005];

struct node2{
	int c,a[10005];
}; 
node2 b[10005];

bool cmp(node1 x,node1 y){
	if(x.u==y.u) return x.w<y.w;
	return x.u<y.u;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++){
			cin>>b[i].a[j];
		}
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=m;i++){
		if(c[a[i].u]==0&&c[a[i].v]==0) c[a[i].u]=1,c[a[i].v]=1,cnt+=a[i].w;
		else continue;
	}
	
	cout<<cnt<<endl;
	return 0;
}
