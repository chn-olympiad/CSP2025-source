#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,c,a[1010],tx,ty;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	stable_sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) if(a[i]==x) {
		c=n*m-i+1;
		break;
	}
	tx=1,ty=1;
	for(int i=1;i<c;i++) {
		if((ty%2==1&&tx==n)||(ty%2==0&&tx==1)) ty++;
		else {
			if(ty%2==1) tx++;
			else tx--;
		}
	}
	cout<<ty<<" "<<tx;
	return 0;
}