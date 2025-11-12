#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int li[n*m+2],meng;
	for (int i=1;i<=n*m;i++) {
		cin>>li[i];
		if (i==1) {
			meng=li[i];
		}
	}
	sort(li+1,li+n*m+1,cmp);
	int set=1;
	for (int j=1;j<=m;j++) {
		if (j%2==1) {
			for (int i=1;i<=n;i++) {
				if (li[set]==meng) cout<<j<<' '<<i<<endl;
				set++;
			}
		}
		else {
			for (int i=n;i>0;i--) {
				if (li[set]==meng) cout<<j<<' '<<i<<endl;
				set++;
			}
		}
	}
	return 0;
}
