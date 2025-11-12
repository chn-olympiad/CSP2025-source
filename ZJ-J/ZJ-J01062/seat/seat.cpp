#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,r,cnt=1,h,l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>r;
	for(int i=1,x; i<n*m; i++) {
		cin>>x;
		cnt+=x>r;
	}
	l=ceil(cnt*1.0/m);
	if(l&1) {
		h=(cnt-1)%m+1;
	} else {
		h=n-(cnt-1)%m;
	}
	cout<<l<<' '<<h;
	return 0;
}
