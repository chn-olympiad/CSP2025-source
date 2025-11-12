#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],c,r;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i=0; i<n*m; i++) cin>>a[i];
	int tmp=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0; i<n*m; i++) if(a[i]==tmp) r=i+1;
	cout<<(r-1)/m+1<<' ';
	if((r-1)/m%2) cout<<n-r%m+1;
	else cout<<(r-1)%m+1;
	return 0;
}
