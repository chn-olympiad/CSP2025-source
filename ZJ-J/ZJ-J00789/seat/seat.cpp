#include <bits/stdc++.h>
using namespace std;
int n,m,x,j=1,t,x1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++) {
		cin>>t;
		if(t>x) {
			j++;
		}
	}
	x1=j%(2*n);
	//cout<<j<<endl;
	cout<<ceil(j*1.0/n)<<" ";
	if(x1==0) {
		x1=2*n;
	}
	if(x1<=n) {
		cout<<x1;
	} else {
		cout<<n*2+1-x1;
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/