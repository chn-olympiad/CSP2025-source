#include<bits/stdc++.h>
using namespace std;
int a[110],b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int y=n*m;
	for(int i=1;i<=y;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+y+1);
	reverse(a+1,a+y+1);
	int d=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[++d];
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[++d];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==k){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
