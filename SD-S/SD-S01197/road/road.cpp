#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans=0;
	bool f=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=0;
	}
	for(int i=1;i<=n;i++){
		ans+=c[i];
	}
	cout<<ans;
	return 0;
} 
