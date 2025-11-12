#include<bits/stdc++.h> 
using namespace std;
const int N=105;
int n,m,a[N];
bool cmp(int x,int y) {
	return x>y;
}
int l(int x,int y) {
	if(x%y==0) return x/y;
	else return (x-1+y)/y;
}
int v(int x,int y) {
	if(x%y==0) return x/y;
	else return (x-1+y)/y;
}
int s(int x) {
	int f=l(x,n),k=x%n;
	if(f%2==0) return n-k+1;
	else {
		if(k==0) return n;else return k;
	}
}
int main() {
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int b,i,j;
	cin>>n>>m;cin>>b;a[1]=b;
	for(i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++) {
		if(a[i]==b) break;
	}
	cout<<v(i,m)<<" "<<s(i);
	return 0;
}
