#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct se {
	int num,id;
} a[1005];
bool cmp(se x,se y) {
	return x.num>y.num;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
//	if(n==1&&m==1){
//		cout<<"1 1";
//		return 0;
//	}
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].num;
		a[i].id=i;
	}
	int t;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i].id==1) {
			t=i;
			break;
		}
	}
	int l=(t-1)/n+1;
	int h;
	if(l%2==1) {
		h=t%n;
		if(h==0) {
			h=n;
		}
	} else {
		h=n-t%n+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
