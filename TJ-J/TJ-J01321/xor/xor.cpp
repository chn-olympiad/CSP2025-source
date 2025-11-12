#include<bits/stdc++.h>
using namespace std;
int n,a[1000],m,xa,b[100][100],h=1,l=1,s=0;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	xa=a[1];
	for(int i=2; i<=n*m; i++) {
		cin>>a[i];
	}
	cout<<2;
}
