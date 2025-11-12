#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,number1=0;
	cin>>n>>m;
	int a[n*m+5],zw[n+5][m+5];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		number1=a[0];
		if(a[i]>a[i-1]){
			int t=a[i-1];
			a[i-1]=a[i];
			a[i]=a[i-1];
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				zw[i][j]=a[i-1];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				zw[i][j]=a[i-1];
			} 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(number1==zw[i][j]){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
