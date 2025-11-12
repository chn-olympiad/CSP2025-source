#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
int n,m;
string s;
long long ans=0;
int c[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	int flag=0;
	for(int i=0; i<n; i++) {
		if(s[i]=='0') {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		ans=1;
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(c[i]<=cnt) {
				cnt++;
			}
		}
		for(int i=1; i<=n-cnt; i++) {
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	ans=1;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(c[i]<=cnt||s[i]=='0') {
			cnt++;
		}
	}
	for(int i=1; i<=n-cnt; i++) {
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
	return 0;
}

