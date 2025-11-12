#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,w,x=1,y=1;
	cin>>n>>m;
	int s[n+2][m+2],a[m*n+2];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	c=a[0];
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int k=0;k<m*n;k++){
		s[x][y]=a[k];
		if(x%2==0){
			y=y-1;
		}else{
			y=y+1;
		}
		if(y-1==n||y==0)x++;	
		if(y-1==n)y--;
		if(y==0)y++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==c){
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	return 0;
}
