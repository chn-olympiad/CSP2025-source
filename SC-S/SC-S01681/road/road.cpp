#include<bits/stdc++.h>
using namespace std;
struct Way{
	int u,v,w;
}W[1000001];
bool comp(Way a,Way b){
	return a.w<b.w;
}
int fa[10001];
int father(int x){
	if(x==fa[x]){
		return x;
	}else{
		return father(fa[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j;
	long long sum=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	for(i=0;i<m;i++){
		cin>>W[i].u>>W[i].v>>W[i].w;
	}
	sort(W,W+m,comp);
	for(i=0;i<m;i++){
		if(father(W[i].u) != father(W[i].v)){
			sum+=W[i].w;
			fa[father(W[i].u)]=W[i].v;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}