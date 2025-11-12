#include <bits/stdc++.h>
using namespace std;
string a;
char g[1000000];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>a;
	long long b=a.size(),c=0;
	for(long long i=0; i<b; i++) {
		if(a[i]<='9'&&a[i]>='0') {

			g[c]=a[i];
			c++;

		}
	}

	for(int i=0; i<c; i++) {
		char mx='0';
		int dz=0;
		for(int j=i; j<c; j++) {

			if(g[j]>=mx) {

				mx=g[j];
				dz=j;

			}
		}

		char o=g[dz];
		g[dz]=g[i];
		g[i]=o;

	}

	for(long long q=0; q<c; q++) {
		cout<<g[q];
	}
	return 0;
}
