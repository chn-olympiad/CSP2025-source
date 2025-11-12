#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,a[10005],c=1,x=1,y=1,c1=1;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		if(a[c]<a[i]) {
			c++;
		}
	}
	while(c!=c1) {
		if(y%2!=0) {
			x++;
			c1++;
			if(x>n) {
				x=n;
				y++;
			}
		} else {
			x--;
			c1++;
			if(x<1) {
				x=1;
				y++;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
