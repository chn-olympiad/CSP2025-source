#include<bits/stdc++.h>
using namespace std;
const int M=1e7+10; 
const int N=1e4+11;
int fa[N],c[20],g[20][10004];
long long sum,s[20];
struct node{
	int x,y,w;
}a[M];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int h(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	fa[fa_x]=fa_y;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			a[m+1].x=j,a[m+1].y=n+i,a[m+1].w=g[i][j];
			m++;}}
	n+=k;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y;
		if(find(x)!=find(y)){
			h(x,y);
			sum+=a[i].w;}}
	cout<<sum;
	return 0;
}