#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+20;
int n,m,k;
int ansz=1e9;
int fa[N];
int mo[15];
struct node{
	int v,u,w;
}ar[N];
int find(int k){
	if(k==fa[k]){
		return k;
	}
	else return fa[k]=find(fa[k]);
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx==yy){
		fa[x]=y;
	}
	else fa[x]=y;
}

bool cmp(node a,node b){
	return a.w<b.w;
}
void kruskal(int kk,int sum){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(ar+1,ar+kk+1,cmp);
	int num=sum-1;
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=ar[i].u,v=ar[i].v;
		int xx=find(u),yy=find(v);
		if(xx==yy){
			continue;
		}
		else{
			merge(xx,yy);
			ans=ans+ar[i].w;
			num--;
		}
		if(num==0) break;
	}
	ansz=min(ans,ansz);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		int cnt=0;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			ar[++cnt].u=u,ar[cnt].v=v,ar[cnt].w=w;
		}
		kruskal(cnt,n);
		cout<<ansz;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
