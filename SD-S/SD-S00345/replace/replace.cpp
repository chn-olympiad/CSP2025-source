/*
弄不死就往死里弄！
不要放弃任何一点分！
先写暴力！发掘特殊性质！
读题读题读题！
int <-> long long 数组大小！ MLE?RE?
图论？DP？
优化一下？
*/

#include <bits/stdc++.h>

#define int long long

#define PSS pair<string,string>

#define mkp make_pair

using namespace std;

const int N=2e5+10;

int n,q;
PSS matches[N];
int len_s[N];
string t_1,t_2;

void readin() {
	cin>>n>>q;
	for(int i=1;i<=n;++i) {
		cin>>matches[i].first>>matches[i].second;
		len_s[i]=matches[i].first.length();
		matches[i].first=' '+matches[i].first;
		matches[i].second=' '+matches[i].second;
	}
}

void solve() {
	for(int i=1;i<=q;++i) {
		cin>>t_1>>t_2;
		if(t_1.length()!=t_2.length()) {
			cout<<0<<"\n";
			continue;
		} 
		int len=t_1.length();
		t_1=' '+t_1;
		t_2=' '+t_2;
		string orig=t_1;
		int ans=0;
		for(int type=1;type<=n;++type) {
			for(int i=1;i<=len;++i) {
				if(i+len_s[type]-1>len) break;
//				cerr<<"Match Place: "<<i<<"\n";
				bool match=false;
				for(int j=1;j<=len_s[type];++j) {
					if(t_1[i+j-1]!=matches[type].first[j]) {
						match=true;
//						cerr<<"#guoguo160\n";
						break;
					}
				}
				if(!match) {
//					cerr<<"Ouch\n";
					for(int j=1;j<=len_s[type];++j) {
						t_1[i+j-1]=matches[type].second[j];
					}
					if(t_1==t_2) ans++;
					t_1=orig;
				}
			}	
		}
		cout<<ans<<"\n";
	}
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	readin();
	solve();
	return 0;
}
