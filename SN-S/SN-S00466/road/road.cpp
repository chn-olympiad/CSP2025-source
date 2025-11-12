#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct ss{
	int s,e,cost;
} a[10010];
int father[10010];
int qp[11][10010];
bool cmp(ss x1,ss y1){
	return x1.cost<y1.cost;
}
int find(int x){
	if(father[x]==x){
		return x;
	}else{
		return father[x]=find(father[x]);
	}
}
signed main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int i=1;i<=m;i++){
		int o1,o2,o3;
		cin>>o1>>o2>>o3;
		a[i].s=o1;
		a[i].e=o2;
		a[i].cost=o3;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>qp[i][j];
		}
	}
	sort(a+1,a+1+m,cmp);
	int ans=0;
	int costn=0;
	for(int i=1;i<=m;i++){
		int p=find(a[i].s);
		int q=find(a[i].e);
		if(p!=q){
			father[p]=q;
			ans+=a[i].cost;
			costn++;
		}
		if(costn==n-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
