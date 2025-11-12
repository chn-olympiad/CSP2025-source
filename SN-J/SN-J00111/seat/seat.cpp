#include <bits/stdc++.h>
using namespace std;
int n,m;
int A[100000];
int B[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>A[i];
	}
	int daan=A[1];
	int x=1;
	int y=1;
	int zhuangtai=0;
	for(int i=1;i<=n*m;i++){
		int b=-2;
		int u;
		for(int j=1;j<=n*m;j++){
			if(A[j]>b){
				b=A[j];
				u=j;
			}
		}
		A[u]=-3;
		if(zhuangtai==1){
			if(x==1){
				B[x][y]=b;
				zhuangtai=2;
				y++;
			}
			if(x<m){
				
				B[x][y]=b;
			}
			if(x==m){
				B[x][y]=b;
			}
			x--;
		}
		if(zhuangtai==0){
			if(x==m){
				B[x][y]=b;
				zhuangtai=1;
				y++;
			}
			if(x<m){
				B[x][y]=b;
				++x;
			}
		}
		if(zhuangtai==2){
			if(x==m){
				B[x][y]=b;
				zhuangtai=1;
				y++;
			}
			if(x>1){
				B[x][y]=b;
			}
			if(x==1){
				B[x][y]=b;
			}
			x++;	
		}
		if(y>n){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(B[i][j]==daan){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
