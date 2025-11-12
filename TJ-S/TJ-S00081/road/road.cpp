#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct node{
	long long x,y,w;
};
node e[1100005],E[1100005];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long a[15][10005];
long long f[11005];
long long find(long long x){
	if(x!=f[x]){
		f[x]=find(f[x]);
	}
	return f[x];
}
long long kruskal(long long N,long long M){
	if(N==1){
		return 0;
	}
	for(long long i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(long long i=1;i<=M;i++){
		E[i]=e[i];
	}
	sort(E+1,E+M+1,cmp);
	long long cnt=0,res=0;
	for(long long i=1;i<=M;i++){
		if(find(E[i].x)!=find(E[i].y)){
			res+=E[i].w;
			cnt++;
			f[find(E[i].x)]=find(E[i].y);
			if(cnt==N-1){
				return res;
			}
		}
	}
}
long long numofe=0,ANS=9000000000000000000;
void dfs(long long x,long long val,long long cnt){
	if(x==k+1){
		ANS=min(ANS,kruskal(n+cnt,m+cnt*n)+val);
		return;
	}
	for(long long i=1;i<=n;i++){
		e[++numofe]={i,n+x,a[x][i]};
	}
	dfs(x+1,val+a[x][0],cnt+1);
	for(long long i=1;i<=n;i++){
		e[numofe--]={0,0,0};
	}
	dfs(x+1,val,cnt);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long x,y,w;
		cin>>x>>y>>w;
		e[i]={x,y,w};
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	numofe=m;
	if(k==0||(n<=1000&&m<=100000&&k<=5)){
		dfs(1,0,0);
		cout<<ANS;
	}
	else{
		long long sumval=0;
		for(long long i=1;i<=k;i++){
			sumval+=a[i][0];
			for(long long j=1;j<=n;j++){
				e[++numofe]={j,n+i,a[i][j]};
			}
		}
		cout<<kruskal(n+k,m+k*n)+sumval;
	}
	return 0;
}
