#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[10005],c;
vector<int> e[10005];
struct node{
	int u,v,w;
}q[1000005];
void f(int x){
	b[x]=1;
	for(int i=1;i<=n;i++){
		int r=e[x][i];
		if(e[i][r]!=0&&b[e[i][r]]==0){
			f(e[i][r]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>q[i].u>>q[i].v>>q[i].w;
		e[q[i].u].push_back(q[i].v);
		e[q[i].v].push_back(q[i].u);
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			c+=q[i].w;
		}
		cout<<c;
	}
	else cout<<0;
	return 0;
}

