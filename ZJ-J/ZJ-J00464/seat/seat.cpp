#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)t=a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	int j=1,k=1;
	for(int i=1;i<=m;i++){
		if(j==1){
			for(j=1;j<=n;j++){
				b[i][j]=a[k];
				k++;
			}
			j=n;
		}
		else if(j==n){
			for(j=n;j>=1;j--){
				b[i][j]=a[k];
				k++;
			}
			j=1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[j][i]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==t)cout<<i<<" "<<j;
		}
	}
	return 0;
}
