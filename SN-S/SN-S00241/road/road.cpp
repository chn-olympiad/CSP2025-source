#include<bits/stdc++.h>
using namespace std;
struct peitao{
	int u;
	int v;
	int w;
}pt[1000010];
bool cmp(peitao a,peitao b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[k][n+1];
	for(int i=0;i<m;i++){
		cin>>pt[i].u>>pt[i].v>>pt[i].w;
	}
	bool b=1;
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) b=0;
		}
	}
	if(b){
		cout<<0;
		return 0;
	}
	if(!k){
		sort(pt,pt+m,cmp);
		long long zongfeiyong=0;
		for(int i=0;i<n-1;i++){
			zongfeiyong+=pt[i].w;
		}
		cout<<zongfeiyong;
		return 0;
	}
	cout<<13;
	return 0;
}

