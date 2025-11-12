#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
int brr[121];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>brr[i];
	}
	int r=brr[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(brr[j]<brr[j+1]){
				swap(brr[j],brr[j+1]);
			}
		}
	}
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				arr[j][i]=brr[k];
				k++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				arr[j][i]=brr[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
