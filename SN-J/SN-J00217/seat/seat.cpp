#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[110];int d[110];
	int b[10][10];
	int c=m*n;
	for(int i=0;i<c;i++) cin>>a[i];
	int k = a[0];
	sort(a,a+c);
	int z=0;

	for(int i=c-1;i>=0;i--)  d[z] = a[i],z++;
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	else if(n==1) {
		for(int i=1;i<=c;i++) {
			if(d[i-1]==k) {
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	else if(m==1) {
		for(int i=1;i<=c;i++) {
			if(d[i-1]==k) {
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	else {
		int x=1,y=1;
		for(int i=1;i<=c;i++) {
			y=(i/4)*2+1;
			if(i%4==1) b[x][y] == d[i-1];
			if(i%4==2) b[x+1][y] == d[i-1];
			if(i%4==3) b[x+1][y+1] == d[i-1];
			if(i%4==4) b[x][y+1] == d[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;i<=m;j++) {
				if(b[i][j]==k){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
