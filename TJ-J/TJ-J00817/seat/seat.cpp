#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y) {
	return x>y;
}
int mp[11][11],a[111];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,fin;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
	fin=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int x=1,y=1,fx=0,i=1;
	while(i<=n*m) {
		mp[x][y]=a[i];
		i++;
		if(fx==0) {
			if(x+1<=n)x++;
			else {
				fx=(fx+1)%4;
			}
		}
		if(fx==2) {
			if(x-1>=1)x--;
			else {
				fx=(fx+1)%4;
			}
		}if(fx==1 or fx==3) {
			if(y+1<=m) {
				y++;
			}
			fx=(fx+1)%4;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(mp[i][j]==fin){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
