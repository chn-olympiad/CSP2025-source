#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],oz;
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int x=1,y=1;
	oz=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==oz) {
			cout<<y<<' '<<x;
			break;
		}
		if(y%2) {
			x++;
			if(x>n)x=n,y++;
		} else {
			x--;
			if(x==0)x=1,y++;
		}
	}
	return 0;
}
