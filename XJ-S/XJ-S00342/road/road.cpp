#include <bits/stdc++.h>
using namespace std;
int m,n,k,vis[10010];
long long ans;
struct node{
	int c1,c2;
	long long jz;
}a[1000010];
bool cmp(node x,node y){
	return x.jz<y.jz;
}
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i].c1>>a[i].c2>>a[i].jz;
		if (a[i].c1>a[i].c2){
			swap(a[i].c1,a[i].c2);
		}
		for (int j=1;j<i;j++){
			if ((a[i].c1==a[j].c1 && a[i].c2==a[j].c2 ) || (a[i].c1==a[j].c2 && a[i].c2==a[j].c1 )){
				i-=1;
				m-=1;
				if (a[i].jz<a[j].jz ){
					a[j].jz=a[i].jz;
				}
			}
		}
	}
	for (int i=1;i<=k;i++){
		int p;
		cin>>p;
		for (int i=1;i<=n;i++){
			cin>>p;
		}
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=n-1;i++){
		ans+=a[i].jz;
	}
	cout<<ans;
	return 0;
}
