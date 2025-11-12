#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int m,n,s;
	int b[m][n];
	int p,sb;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			sb=b[1][1];
	}}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]<b[i][j+1]){
				s=b[i][j];
				b[i][j]=b[i][j+1];
				b[i][j+1]=s;
			}if(b[i][j]<b[i+1][j]){
				s=b[i][j];
				b[i][j]=b[i+1][j];
				b[i+1][j]=s;
			}if(b[i][j]<b[i+1][j+1]){
				s=b[i][j];
				b[i][j]=b[i+1][j+1];
				b[i+1][j+1]=s;
			}if(b[i][j]<b[i-1][j-1]){
				s=b[i][j];
				b[i][j]=b[i-1][j-1];
				b[i-1][j-1]=s;
			}if(b[i][j]<b[i-1][j]){
				s=b[i][j];
				b[i][j]=b[i-1][j];
				b[i-1][j]=s;
			}if(b[i][j]<b[i][j-1]){
				s=b[i][j];
				b[i][j]=b[i][j-1];
				b[i][j-1]=s;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==sb){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
