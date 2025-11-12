#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int b[500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(b[i]>b[1]){
			ans++;
		}
	}
	if(ans==1){
		cout<<"1"<<" "<<"1";
		return 0;
	}
	for(int i=1;i<=m;i++){//iÁÐ 
		if(i%2==1){
			for(int j=1;j<=n;j++){//jÐÐ 
				a[i][j]+=(i-1)*n+j;
				if(a[i][j]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[i][j]+=(i-1)*n+n-j+1;
				if(a[i][j]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
2 10
1 19 2 3 4 5 6 7 8 9 10 51 52 53 54 55 56 57 58 59 60
*/
