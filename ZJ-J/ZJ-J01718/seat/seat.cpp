#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,p;
struct no {
	int x,id;
}a[10010];
bool cmp(no q,no h) {
	return q.x>h.x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i].x;a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	x=1;y=1;p=1;
	while(p<=n*m) {
		if(a[p].id==1) {
			cout<<y<<" "<<x;
			return 0;
		}
		if(y&1) {
			x++;
			if(x>n) x=n,y++;
		}
		else {
			x--;
			if(x<1) x=1,y++;
		}
		p++;
	}
	return 0;
}
