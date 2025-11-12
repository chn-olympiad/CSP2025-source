#include <bits/stdc++.h>
using namespace std;
int n,m,lz,a[105],h[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}lz=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int sum=1;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				h[i][j]=a[sum];
				if(h[i][j]==lz){
					cout<<j<<' '<<i;
					return 0;
				}sum++;
			}
		}else if(j%2==0){
			for(int i=n;i>=1;i--){
				h[i][j]=a[sum];
				if(h[i][j]==lz){
					cout<<j<<' '<<i;
					return 0;
				}sum++;
			}
		}
	}
	return 0;
}
