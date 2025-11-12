#include<bits/stdc++.h>
using namespace std;
int a[1001],b[101][101];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int z=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1;
	for(int j=1;j<=m;j+=2){
		for(int i=1;i<=n;i++){
			b[i][j]=a[x];
			x++;
		}
		for(int i=n;i>=1;i--){
			b[i][j+1]=a[x];
			x++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==z){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
