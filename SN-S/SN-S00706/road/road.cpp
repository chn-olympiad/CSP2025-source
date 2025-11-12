#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100010],b[100010],c[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int num=0;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		num+=c[i];
	}
	int a,b;
	for(int j=1;j<=k;j++){
		cin>>a;
		for(int i=1;i<=n;i++){
			cin>>b;
		}
	}
	cout<<num;
	return 0;
} 
