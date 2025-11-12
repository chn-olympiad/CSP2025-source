#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int n=0;
int m=0;
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	int d=0;
	int shu=0;
	d=a[1][1];
	for(int l=1;l<=n*m;l++){
	
		for(int i=n;i>1;i--){
			for(int j=m;j>1;j--){
				if(a[i][j]>=a[i-1][j-1]){
					shu=a[i][j];
					a[i][j]=a[i-1][j-1];
					a[i-1][j-1]=shu;
				}
			shu=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(d==a[i][j]){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}

