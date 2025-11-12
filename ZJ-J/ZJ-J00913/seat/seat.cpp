#include<bits/stdc++.h>
using namespace std;
int a[110]= {0};
int main() {
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
	}
	int R=a[0];
	sort(a+0,a+n*m);
	int c=1,r=1,w=1;
	for(int i=n*m-1; i>=0; i--) {
		if(a[i]==R) {
			break;
		}
		if(r==n&&((c&1)==1)) {
			w=-1;
			c++;
		} else if(r==1&&((c&1)==0)) {
			c++;
			w=1;
		} else {
			r+=w;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
