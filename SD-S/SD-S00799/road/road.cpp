#include<algorithm>
#include<iostream>
using namespace std;
struct p{
	int u,v,w,id;
}a[1100010];
int f[1100010];
int c[1100010];
bool v[1100010];
int n,m,k,sum;
bool cmp(p a,p b){return a.w<b.w;}
int fin(int x){
	if(f[x]!=x)return fin(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].id=0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			m++;
			cin>>a[m].w;
			a[m].u=n+i;
			a[m].v=j;
			a[m].w+=c[i];
			a[m].id=i;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(fin(a[i].u)!=fin(a[i].v)){
			f[fin(a[i].u)]=fin(a[i].v);
			sum+=a[i].w;
		}
	}
	cout<<sum;
	return 0;
}
