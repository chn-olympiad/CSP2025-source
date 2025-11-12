#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int t;
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[k];
				k++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==t){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
