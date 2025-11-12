#include<bits/stdc++.h>

using namespace std;
string s;
int c[501];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num=0;
	long long ans=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		if(c[i]!=0) num++;
	}
	if(num>=m) {
		for(int i=n; i>=1; i--) {
			ans=ans*i%998244353;
		}
		cout<<ans;
	} else {
		cout<<0;
	}
	return 0;
}