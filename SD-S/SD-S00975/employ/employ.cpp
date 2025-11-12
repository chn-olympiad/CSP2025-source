#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int cc[506],s0[506];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,maxc=-1,sl;
	string s;
	cin>>n>>m>>s;
	sl=s.size();
	for (int i=0,c; i<n; i++) {
		cin>>c;
		cc[c]++;
		maxc=max(maxc,c);
	}
	for (int i=maxc; i>=0; i--) {
		cc[i]+=cc[i+1];
	}
	if (s[0]=='0') s0[0]=1;
	for (int i=1; i<sl; i++) {
		s0[i]=s0[i-1];
		if (s[i]=='0') s0[i]++;
	}
	long long res=0;
	for (int i=sl-1,cnt=0; i>=0; i--) {
		if (s[i]=='1') {
			if (!res) res=1;
			res*=cc[s0[i]+1]-cnt++;
			res%=MOD;
		}
	}
	cout<<res;
	return 0;
}

