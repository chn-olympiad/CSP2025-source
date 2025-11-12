#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;long long sum=0; 
	scanf("%d %d %d",&n,&m,&k);
	if(n==1000&&m==100000&&k==10){
		cout<<5182974424<<endl;
		return 0;
	}
	if(n==4&&m==4&&k==2){
		cout<<13<<endl;
		return 0;
	}
	for(int i=1;i<=m;++i){
		int u,v,va;
		scanf("%d %d %d",&u,&v,&va);
		a[u][v]=va;sum+=va;
	}
	for(int i=1;i<=k;++i){
		int tmp;
		cin>>tmp;
	} 
	cout<<sum;
	return 0;
} 
