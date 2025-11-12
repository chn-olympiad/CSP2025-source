#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[20];
char ch;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch) {
		if(ch>='0'&&ch<='9') x[ch^48]++;
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=x[i];j++) cout<<i;
	}
	return 0;
}