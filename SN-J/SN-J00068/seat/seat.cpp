#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[110],g,f;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	f=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==0){
				a[n-j+1][i]=b[++g];
			}
			else a[j][i]=b[++g];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==f){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
