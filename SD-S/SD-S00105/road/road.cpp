#include<bits/stdc++.h>
#define N 20000
using namespace std;
struct bian{
	long long u,v,w;
}e[N*1000];
long long n,m,k,arr[N],c[15][N];
bool cmp(bian a,bian b){
	return a.w<b.w;
}
long long head(long long a){
	if(arr[a]==a) return a;
	return arr[a]=head(arr[a]);
}
void merge(int a,int b){
	long long ha=head(a),hb=head(b);
	arr[ha]=hb;
}
void shu(){
	long long sum=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(head(e[i].u)==head(e[i].v)) continue;
		merge(e[i].u,e[i].v);
		sum+=e[i].w;
	} 
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) arr[i]=i;
	for(int i=1;i<=m;i++) scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	if(k==0) shu();
	else{
		for(int i=1;i<=k;i++) arr[i+n]=i+n;
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				scanf("%d ",&c[i][j]);
				if(j!=0) e[++m]={n+i,j,c[i][j]};
			}
		}
		shu();
	}
	return 0;
}
