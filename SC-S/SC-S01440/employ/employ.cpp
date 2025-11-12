#include <bits/stdc++.h>
using namespace std;
const int N = 5e2+5;
const int MOD = 998244353;
int n,m;
string str;
int p[N];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	int mx=INT_MIN;
	for(int i=1;i<=n;i++) {
		cin>>p[i];
		mx = max(mx,p[i]);
	}
	
	bool cut=true;
	int cnt=0;
	for(int i=0;i<=(int)str.size();++i) {
		char ch = str[i];
		if(ch != '1') {
			cut = false;
			if(!cnt) cnt = i+1;
		}
	}
	
	if(cut) {
		cout<<0<<"\n";
		return 0;
	}
	if(mx < cnt) {
		cout<<0<<"\n";
	}
	return 0;
}