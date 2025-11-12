#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,f[10010],xc[11][10010];
struct node{
	int u,v,m;
}q[1000010];
bool cmp(node a,node b){
	return a.m<b.m;
}
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	return ;
}
int find(int a){
	if(f[a]==a) return a;
	else return f[a]=find(f[a]);
}
void h(int a,int b){
	int x=find(a);
	int y=find(b);
	f[x]=y;
	f[a]=find(a);
	return ;
}
void le(){
	for(int i=1;i<=n;i++){
		
		if(find(q[i].u)!=find(q[i].v)){
			h(q[i].u,q[i].v);
			cnt+=q[i].m;
		}
		f[q[i].u]=find(q[i].u),f[q[i].v]=find(q[i].v);
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>q[i].u>>q[i].v>>q[i].m;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;i<=n;i++){
			cin>>xc[i][j];
		}
	}
	sort(q+1,q+n+1,cmp);
	le();
	cout<<cnt<<endl;
	return 0;
}
