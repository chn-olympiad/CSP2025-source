#include<bits/stdc++.h>
using namespace std;
int a[105];
int c[105];
int b[20][20];
int cc=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cc=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1,j=n*m;j>=1;j--,i++){
		c[i]=a[j];
	}
	int ant=0;
	for(int i=1;i<=n*m;i++){
		if(c[i]==cc){
			ant=i;
			break;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			b[i][1]=i;
		}
	}else{
		for(int i=1;i<=n;i++){
			b[i][1]=i;
		}
		for(int i=n;i>=1;i--){
			b[i][2]=n+(n-i)+1;
		}
		for(int i=3;i<=m;i++){
			for(int j=1;j<=n;j++){
				b[j][i]=b[j][i-2]+2*n;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ant==b[i][j]){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
