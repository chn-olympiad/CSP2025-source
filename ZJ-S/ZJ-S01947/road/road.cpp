#include<bits/stdc++.h>
using namespace std;
struct node{
	int from,to,w;
}a[1000005];
int n,m,k,sum=0;
int c[12],f[12][10005];
int fa[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void Union(int x,int y){
	if(find(x)!=find(y)) fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].from>>a[i].to>>a[i].w;
	}
	int flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
			if(f[i][j]!=0) flag=0;
		}
	}
	if(k==0) flag=0;
	if(flag){
		cout<<0;
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<m;i++){
		if(find(a[i].from)!=find(a[i].to)){
			Union(a[i].from,a[i].to);
			sum+=a[i].w;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}