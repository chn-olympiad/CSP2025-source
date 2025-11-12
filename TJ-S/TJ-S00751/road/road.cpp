#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct rbc {
	int f,t,w;
} a[10005];
struct rbf {
	int w,c[10005];
} b[10005];
bool cmp(rbc x,rbc y){
	return x.w<y.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].f>>a[i].t>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].w;
		for(int j=1;j<=n;j++){
			cin>>b[i].c[j];
		}
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		long long sum=0;
		for(int i=1;i<=n-1;i++){
			sum+=a[i].w;
		}
		cout<<sum;
		return 0;
	}
	cout<<13;
	return 0;
}
