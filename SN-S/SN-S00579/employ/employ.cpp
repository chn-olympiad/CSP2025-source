#include <bits/stdc++.h>
using namespace std;
long long n,m,c,ans=1,p=998224353;
string s;
long long a[1000];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<=s.size(); i++) {
		if(s[i]=='0'){
			n--;
		}
	}
	if(m>n){
		m=n;
	}
	for(int i=n; i>n-m; i--) {
		ans*=i;
		ans%=p;
	}
	cout<<ans;
	return 0;
}
