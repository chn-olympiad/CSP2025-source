#include<bits/stdc++.h>
using namespace std;
long long a[10005][100005];
int main(){
	int n,m,k; 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j]>>a[i][j+1]>>a[i][j+2];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
	}}return 0;}
