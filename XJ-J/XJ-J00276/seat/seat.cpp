#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m];
	for(int i=0;i<n*m;i++) {
		cin>>s[i];
	}
	int rseat=s[0];
	sort(s,s+n*m);
	int xb=0;
	for(int i=0;i<n*m;i++) {
		if(s[i]==rseat) {
			xb=i;
		}
	}
	xb=n*m-xb;
	int xbi=-1,xbj=-1,count=0;
	for(int i=0;i<m;i++) {
		if(i%2==0) {
			for(int j=0;j<n;j++) {
				count++;
				//cout<<1<<" "<<i<<" "<<j<<" "<<count<<endl;
				if(xb==count) {
					xbi=i;
					xbj=j;
				}
			}
		}else if(i%2==1) {
			for(int j=n-1;j>=0;j--) {
				count++;
				//cout<<0<<" "<<i<<" "<<j<<" "<<count<<endl;
				if(xb==count) {
					xbi=i;
					xbj=j;
				}
			}
		}
	}
	cout<<xbi+1<<" "<<xbj+1;
	return 0;
}
