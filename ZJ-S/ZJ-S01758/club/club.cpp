#include<bits/stdc++.h>
using namespace std;
int n,s1=0,s2=0,Max=0,a[1005][4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2]==0) s1++;
			if(a[i][3]==0) s2++;
		}
		if(s1==n&&s2==n) {
			for(int i=1; i<n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(a[j][1]<a[i][1]) swap(a[i][1],a[j][1]);
				}
			}
			for(int i=1; i<=(n/2); i++) {
				Max+=a[i][1];
			}
			cout << Max;
		}
	}
	return 0;
}
