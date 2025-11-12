#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sc,st[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j&1){//odd
			for(int i=1;i<=n;i++) st[i][j]=a[(j-1)*n+i];
		}
		else{//even
			for(int i=n;i;i--) st[i][j]=a[(j-1)*n+n-i+1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(st[i][j]==sc){ 
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	return 0;
}
