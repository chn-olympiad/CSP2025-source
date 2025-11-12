#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[a.size()]={},c=0;
	for(int i=0; i<a.size(); i++) {
		if(a[i]>='0'&&a[i]<='9') {
			b[c]=a[i]-'0';
			c++;
		}
	}
	for(int i=0; i<c; i++) {
		for(int j=0; j<c; j++) {
			if(b[i]>b[j]){
				int t;
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(int i=0; i<c; i++) {
		cout<<b[i];
	}
	return 0;
}
