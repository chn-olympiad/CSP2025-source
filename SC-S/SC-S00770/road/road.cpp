#include<bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
int c[100100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >>n>>m>>k;
	int o=0;
	for(int i=1;i<=m;i++){
		cin >>a[i]>>b[i]>>c[i];
		o+=c[i];
	}
	int s;
	for(int i=1;i<=k;i++){
		cin >>s;
		for(int j=1;j<=n;j++){
			cin >>s;
		}
	}
	cout <<o;
	return 0;
} 

