#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1],seat[n+1][m+1]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1);
	int hang=1,lie=1;
	for(int i=n*m;i>=1;i--){
		if(hang==n+1){
			lie+=1;
			hang=1;
		}
		if(lie%2==1){
			seat[hang][lie]=a[i];
			hang+=1;
		}
		else{
			seat[n-hang+1][lie]=a[i];
			hang+=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==R){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
