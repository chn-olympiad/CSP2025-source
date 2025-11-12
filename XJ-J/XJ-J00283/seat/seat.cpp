#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a[230],j=1,r,n,m;
	cin>>n>>m;
	int y=n*m;
	for(int i=1;i<=y;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+y+1);
	for(int i=1;i<=n;i++) {
		if(j==1){
			for(j=1;j<=m;j++) {
				if(a[y]==r) cout<<i<<' '<<j;
				y--;
			}
			j=m;
		}
		else if(j==m){
			for(j=m;j>=1;j--){
				if(a[y]==r) 
				cout<<i<<' '<<j;
				y--;
			} 
			j=1;
		}
	}
	return 0;
}

