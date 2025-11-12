#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[10000007];
int fa[10000007];
int s;
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void zxscs(int t){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int fa1=find(a[i].u),fa2=find(a[i].v);
		if(fa1<=n&&fa1!=fa2){
			fa[a[i].u]=fa2;
			s+=a[i].w;
			t++;
			if(t==n-1)return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
	}
	if(k==0){
		zxscs(0);
		cout<<s;
	}
	else cout<<0;
	return 0;
}
