#include<bits/stdc++.h>
using namespace std;
string a;
int b[105];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int c=a.size();
	if(c==1) {
		cout<<a;
		return 0;
	}
	for(int i=0; i<c; i++) {
		if(a[i]-'0'<=9&&a[i]-'0'>=0) {
			b[a[i]-'0']++;
		}
	}
	int kg=0;
	int zz=0;
	for(int i=9; i>=0; i--) {
		if(b[i]!=0) {
			if(i!=0) {
				kg=1;
			}
			if(kg==1) {
				for(int j=0; j<b[i]; j++) {
					cout<<i;
					zz++;
				}
			}
		}

	}
	if(zz==0)
	{
		cout<<0;
	}
	return 0;
}
