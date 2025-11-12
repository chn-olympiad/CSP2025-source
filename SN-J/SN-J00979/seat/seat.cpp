#include <bits/stdc++.h>
using namespace std;
int m,n;
int x[101];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=0; i<k; i++) {
		cin>>x[i];
	}
	int o=x[0];
	for(int i=0; i<k; i++) {
		char mx=0;
		int dz=0;
		for(int j=i; j<k; j++) {

			if(x[j]>=mx) {

				mx=x[j];
				dz=j;

			}
		}
		int o=x[dz];
		x[dz]=x[i];
		x[i]=o;

	}
	int u=0;
	for(int i=0; i<k; i++) {
		if(x[i]==o) {
			u=i+1;
		}
	}
//	cout<<u<<"   ";
	int f=u/n;
	if(u%n==0) {
		if(f%2==0) {

			cout<<f<<" 1";
		} else {

			cout<<f<<' '<<n;
		}

	} else {
		f++;

		if(f%2==0) {

			int z=n-u%n+1;
			cout<<f<<' '<<z;
		} else {

			int z=u%n;
			cout<<f<<' '<<z;
		}
	}
	return 0;

}
