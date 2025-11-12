#include<bits/stdc++.h>
using namespace std;
int n,a[1000],m,xa,b[100][100],h=1,l=1,s=0;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	xa=a[1];
	for(int i=2; i<=n*m; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(s==0) {
			b[h][l]=a[i];
			if(h==n) {
				l++;
				s=1;
				continue;
			}
			h++;
		}else{
			b[h][l]=a[i];
			if(h==1) {
				l++;
				s=0;
			}	
			h--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==xa){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
}
