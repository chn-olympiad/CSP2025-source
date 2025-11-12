#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10],a[5][20000],sum;
int aw[100000],z=0;
struct dl{
	int u,v,w;
}road[100000];
bool pd(dl z,dl x){
	return z.w<=x.w;
}
int xz(int d){
	if(d==aw[d])return d;
	return xz(aw[d]);
}
int search(int n,int m,dl road[100000]){
	dl rd[100000];
	for(int i=0;i<m;i++){
		rd[i].u=road[i].u;
		rd[i].v=road[i].v;
		rd[i].w=road[i].w;
	}
	z=0;
//	for(int i=0;i<m;i++){
//		cout<<rd[i].u<<" "<<rd[i].v<<" "<<rd[i].w<<endl;
//	}
	sort(rd,rd+m,pd);
	for(int i=0;i<n;i++)aw[i]=i;
	for(int i=0;i<m;i++){
		int p=xz(rd[i].u);
		int q=xz(rd[i].v);
		if(p!=q){
			z+=rd[i].w;
			aw[p]=q;
		}
	}
//	cout<<z<<endl;
	return z;
}
void zj(int i,int s,int q){
	for(;i<k;i++){
		for(int j=0;j<n;j++){
			road[m+s*n+j].u=i+n+1;
			road[m+s*n+j].v=j+1;
			road[m+s*n+j].w=a[i][j];
//			cout<<a[i][j]<<" "<<road[m+s*n+j].w<<endl;
		}
		sum=min((q+c[i]+search(n+1,m+s*n+n,road)),sum);
		zj(i+1,s+1,q+c[i]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	sum=search(n,m,road);
	zj(0,0,0);
	cout<<sum;
	return 0;
}
