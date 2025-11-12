#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,q;
}a[1000000];
long long n,m,k,b[11][100000],c[1000000],ans;
bool cmp(node aa,node bb){
	return aa.q<bb.q;
}
bool cmp2(long long aa[],long long bb[]){
	return aa[1]<bb[1];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		c[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].q;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(b[i][1]>b[i+1][1]){
			swap(b[i],b[i+1]);
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=2;j<=n;j++){
			if(b[i][j]>b[i][j+1]){
				swap(b[i][j],b[i][j+1]);
			}
		}
	}
	for(int i=1;i<=m/2;i++){
		ans+=a[i].q;
	}
	for(int i=1;i<=k/2;i++){
		ans+=b[i][1];
	}
	for(int i=1;i<=k/2;i++){
		for(int j=2;j<=n/2+1;j++){
			ans+=b[i][j];
		}
	}
	cout<<ans;
	return 0;
}
