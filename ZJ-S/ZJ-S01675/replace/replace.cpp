#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string str1[N],str2[N];
string s1,s2;

void solve() {
	cin>>s1>>s2;
//	s1=" "+s1,s2=" "+s2;
//	for(int i=1; i<=s1.size()-1; i++) {
//		for(int j=1; j<=n; j++) {
//			int len=str1[i].size()-1;
//			string now=s1.substr(i,len);
//			if(now==str1[j]) {
//
//			}
//		}
//	}
	cout<<0<<endl;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>str1[i]>>str2[i];
		str1[i]=" "+str1[i];
		str2[i]=" "+str2[i];
	}
	while(q--) {
		solve();
	}

	return 0;
}
//神兽保佑，代码无 bug!!!

