#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1100];
int ans1,ans2;
bool cmp(int x,int y) {
	return x>y;
}

int main() {
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int tmp=a[1],t;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==tmp) {
			t=i;
			break;
		}
	}
	ans1=(t/n)+(t%n!=0);
	if(ans1%2) {
		ans2=t-(ans1-1)*n;
	} else {
		ans2=n-(t-(ans1-1)*n)+1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
