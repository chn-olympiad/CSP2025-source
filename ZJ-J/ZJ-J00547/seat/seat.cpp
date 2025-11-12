#include<bits/stdc++.h>
using namespace std;
struct node {
	int x;
	bool h;
} a[110];
bool cmp(node x,node y) {
	if(x.x<y.x ) return 0;
	else return 1;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].x ;
	}
	a[1].h =1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {

				if(a[(i-1)*n+j].h ) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		} else {
			for(int j=1; j<=n; j++) {

				if(a[(i-1)*n+j].h ) {
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
