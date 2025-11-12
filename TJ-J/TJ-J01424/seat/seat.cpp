#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500];
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ai=0;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
		if(i==1) {
			ai=a[i];
		}
	}
	sort(a+1,a+n*m+1,greater<int>());
	if(n==1) {
		for(int i=1; i<=n*m; i++) {
			if(a[i]==ai) {
				cout<<i<<" "<<1<<endl;
				return 0;
			}
		}
		return 0;
	}
	if(m==1) {
		for(int i=1; i<=n*m; i++) {
			if(a[i]==ai) {
				cout<<1<<" "<<i<<endl;
				return 0;
			}
		}
		return 0;
	}
	int x=1,y=1;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==ai) {
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		if(i==1) {
			y++;
			continue;
		}
		if(y==n) {
			if(x&1) {
				x++;
			} else {
				y--;
			}
			continue;
		}
		if(y==1) {
			if(x&1) {
				y++;
			} else {
				x++; 
			}
			continue;
		}
		if(x&1){
			y++;
		}else{
			y--;
		}
	}
}
//3 3
//94 95 96 97 98 99 100 93 92
