#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int c,r,R,ma=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			if(i==1&&j==1){
				R=x;
			}
			if(x>R){
				ma++;
			}
		}
	}
	c=(ma+n-1)/n;
	if(c%2==0){
		r=n-ma%n+1;
	}else {
		if(ma%n==0){
			r=n;
		}else r=ma%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
