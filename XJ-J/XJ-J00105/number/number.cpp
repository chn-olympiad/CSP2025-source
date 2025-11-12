#include <bits/stdc++.h>
using namespace std;
char a[1000000];
int b[1000000],c,d;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a
	for(int i=1; i <= size.s(a); i++) {
		if(int(a[i])>=48&&<=57) {
			b[c]=int(a[i])-48;
			c++;
		}
	}
	for(int i=1; i<=size.s(b); i++) {
		for(int j=i; j<=size.s(b); j++) {
			if(b[i]>b[i+1]) {
				d=b[i];
				b[i]=b[i+1];
				b[i+1]=d;
			}
		}
	}
	for(int i=1; i<=size.s(b); i++) {
		cout<<b[i];
	}
	return 0;
}
