#include<bits/stdc++.h>
using namespace std;
int arr[305];
int a[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(i==1){
			r=arr[i];
		}
	}
	sort(arr+1,arr+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=arr[n*j+i-n];
			}
		}else{
			for(int i=1;i<=n;i++){
				a[i][j]=arr[n*j-i+1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

