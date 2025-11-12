#include<bits/stdc++.h>
using namespace std;
int a[500004],b[500004]= {0,0};
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,max_=0;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2; i<=n; i++) {
		cin>>a[i];
		b[i-1]=(a[i]^a[i-1])+b[i-2];
	}
	for(int i=1+m; i<=n; i++) {
		max_=max(b[i- 1]-b[i-m-2],max_);
	}
	cout<<(max_-m);
	return 0;
}
