#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
vector<int>c;
int I(unsigned int n) {
	if(n==1)
		return 1;
	return I(n-1)*(n%MOD)%MOD;
}
int A() {
	return I(n)%MOD;
}
bool Ac(string s) {
	while(s[0]=='1')s.erase(0);
	return s.empty();
}

bool c1(string s) {
	int cnt=0;
	while(s[0]=='1') {
		s.erase(0);
		cnt++;
	}
	return cnt;
}
bool SEc(string s) {
	int i;
	for(i=1; s[0]=='1'&&i<=n; i++)s.erase(0);
	return i==n;
}
int main() {
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	c.resize(n+1);
	for(int i=1; i<=n; i++) cin>>c[i];
	if(Ac(s)) {
		cout<<A()%MOD<<endl;
		return 0;
	}
	if(n==m) {
		if(SEc(s))
			cout<<A()%MOD<<endl;
		else
			cout<<0<<endl;
		return 0;
	}
	if(c1(s)<m) {
		cout<<0<<endl;
		return 0;
	}
	return 0;
}