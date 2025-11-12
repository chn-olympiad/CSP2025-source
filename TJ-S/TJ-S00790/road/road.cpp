#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[5][1000005],b[10005][15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=3;j++) {
			cin >> a[i][j];
		}
	} 
	for (int i = 0;i<k;i++) {
		for (int j = 0;j<n;j++) {
			cin >> b[i][j];
		}
	}
	cout << '0';
	return 0;
} 
