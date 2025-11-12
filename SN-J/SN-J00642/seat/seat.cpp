#include<bits/stdc++.h>
using namespace std;
#define int long long
struct seat {
	int x,y,t,r;
} a[115];
bool cmp(seat a,seat b) {
	return a.t>b.t;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int w;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].t;
		if(i==1) {
			a[i].r=1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i].r==1) {
			w=i;
		}
	}
	int ans1=1,ans2=-1;
	int t=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			ans2++;
			t++;
			if(t==w||ans1==n) {
				cout<<ans1<<" "<<ans2;
				return 0;
			}
			if(ans2==m) {
				ans1++;
				break;
			}
		}
		ans1++;
		for(int j=m; j>0; j++) {
			ans2--;
			t++;
			if(t==w||ans1==n) {
				cout<<ans1<<" "<<ans2;
				return 0;
			}
			if(ans2==1) {
				ans1++;
				break;
			}
		}
		if(t==w) {
			cout<<ans1<<" "<<ans2;
			return 0;
		}
		ans1++;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
