#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
struct node{
	int x,y,m;
}a[1000001];
bool cmp(node a,node b){
	return a.m<b.m;
}
int fa[10001]={};
void in(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	in(); 
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].m;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			fa[find(a[i].x)]=fa[find(a[i].y)];
			ans+=a[i].m;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
