#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=1145140;

string s;
int t[10];

signed main() {
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.length();
	s=" "+s;
	for(int i=1; i<=len; i++) {
		t[s[i]-'0']++;
	}
	for(int i=9; i>=0; i--) {
		for(int j=1; j<=t[i]; j++) {
			cout<<i;
		}
	}
}
