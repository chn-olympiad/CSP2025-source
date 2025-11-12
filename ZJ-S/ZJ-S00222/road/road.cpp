#include<bits/stdc++.h>
using namespace std;
struct A{
	int u,v;
	long long w; 
}a[2000005];
long long sum=0;
int fa[2000005]={};
int find(int x){
	if(fa[x]!=x)return fa[x];
	return x;
}
bool cmp(A x,A y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}sum=m;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			A x;
			cin>>x.w;
			x.u=i;x.v=j;
			sum++;
			a[sum]=x;
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		fa[i]=i;
	}
	long long cost=0,s=0;
	for(int i=1;i<=sum;i++){
		int u=a[i].u;int v=a[i].v;long long w=a[i].w;
		if(find(u)!=find(v)){
			fa[v]=find(u);
			cost+=w;s++;
		}
		if(s==n)break;
	}
	cout<<cost;
	return 0;
	
} 

