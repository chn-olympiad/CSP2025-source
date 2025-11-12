#include<iostream>
#include<algorithm>
#include<string>
#define int long long
using namespace std;
const int N = 505, M = 998244353;

int n,m,c[N],space[N],ans = 1,cnt;
string s;

int jc() {
	int res = 1;
	for(int i=n;i>=1;++i) (res*=i) %= M;
	return res;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	cin>>n>>m;
	cin>>s;
	int t = 0, sz = s.size();
	for(int i=0;i<sz;++i) {
		if(s[i]=='0') {
			++t;
		}
	}
	if(t<m) {
		cout<<0;
		return 0;
	}
	if(m==1 || t==n) {
		cout<<jc();
		return 0;
	}
	if(n==m) {
		cout<<0;
		return 0;
	}
	
	cout<<jc();
	return 0;
}