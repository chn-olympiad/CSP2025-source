#include<bits/stdc++.h>
using namespace std;
int n[10010];
int a[110][110];
int b[110][110];
int c[110][110];
int maxn[110][110];
int num[6];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,vis,za,zb,zc;
cin >> t;
for(int i = 1;i<=t;i++){
	cin >> n[i];
	for(int j = 1;j<=n[i];j++){
		cin >>a[i][j] >> b[i][j]>> c[i][j];
	}
}
for(int i = 1;i<=t;i++){
	if(n[i] == 2){
	int l=max(a[i][1] + b[i][2],a[i][1] + c[i][2]);
	int v=max(b[i][1]+a[i][2],b[i][1]+c[i][2]);
	int r=max(c[i][1] + a[i][2],c[i][1]+b[i][2]);
	int pg=max(l,v);
	int gg=max(pg,r);
	maxn[i][1] = gg;
	continue;
}	
	za= n[i]/2;
	zb = n[i]/2;
	zc= n[i]/2;
	for(int j = 1;j<=n[i];j++){
		if(a[i][j] > b[i][j]&&a[i][j] > c[i][j]&&za>0&&a[i][j] > a[i][j+1]){
			vis = a[i][j];
			za--;
		}
		if(b[i][j] > a[i][j]&&b[i][j] > c[i][j]&&zb>0){
			vis = b[i][j];
			zb--;
		}
		if(c[i][j] > b[i][j]&&c[i][j] > a[i][j]&&zc>0){
		vis = c[i][j];
		zc--;
		}	
		maxn[i][j] = vis;
	}	
}
for(int i = 1;i<=t;i++){
	for(int j = 1;j<=n[i];j++){
		num[i] += maxn[i][j];
	}
	cout << num[i] << endl;
}
return 0;
} 
