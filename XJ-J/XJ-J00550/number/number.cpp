#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int t,x;
int a[MAXN],b[MAXN];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[i]=s[i]-'0';
			x++;
//			cout<<a[i];
		}
	}
	for(int i=0; i<x; i++) {
		b[i]=a[i];
	}
	for(int i=0; i<x; i++) {
		for(int j=i+1; j<x; j++) {
			if(b[i]<b[j]) {
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
//			cout<<b[i]<<b[j]<<endl;
		}
	}
	for(int i=0; i<x; i++) {
		cout<<b[i];
	}
	return 0;
}
