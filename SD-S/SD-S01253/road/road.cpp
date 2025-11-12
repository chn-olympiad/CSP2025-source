#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[100015];
int cnt=0;
struct s{
	int x;
	int y;
	int z;
}a[2000015];
int cmp(s x,s y){
	return x.z>y.z;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int join(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy){
		fa[xx]=yy;
		return 1;
	}
	return 0;
}
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=0;i<k;i++){
		int c,x;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>x;
			a[m+i*3+j].x=n+i;
			a[m+i*3+j].y=j;
			a[m+i*3+j].z=c+x;
		}
	}
	sort(a+1,a+m+3*k+1,cmp);
	for(int i=1;i<=m+3*k;i++){
		if(join(a[i].x,a[i].y)){
			cnt+=a[i].z;
		}
	}
	cout<<cnt<<"\n";
	
	return 0;
}
