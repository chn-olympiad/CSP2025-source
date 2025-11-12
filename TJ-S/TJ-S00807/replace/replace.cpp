#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+1,M = 5e6+1;
int n,q,nxt[M];
string s[N][3];
void build_nxt(const string &str){
	for(int i = 0;i<str.size();++i){
		nxt[i] = 0;
	}
	int i = 2,j = 0;
	for(i;i<str.size();++i){
		while(j&&str[i]!=str[j+1]){
			j = nxt[j];
		}
		if(str[i] == str[j+1]){
			++j;
		}
		nxt[i] = j;
	}
}
int kmp(const string &s1,const string &s2,string t,const string &to){
	int j = 0,cnt = 0;
	for(int i = 1;i<s1.size();++i){
		while(j&&s1[i]!=s2[j+1]){
			j = nxt[j];
		}
		if(s1[i] == s2[j+1]){
			++j;
		}
		if(j == s2.size()-1){
			string str = s1;
			for(int k = i-j+1;k<=i;++k){
				str[k] = to[k-(i-j)];
			}
			cnt+=(str == '#'+t);
		}
	}
	return cnt;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i<=n;++i){
		cin >> s[i][1] >> s[i][2];
		s[i][1] = '#'+s[i][1];
		s[i][2] = '#'+s[i][2];
	}
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size()!=t2.size()){
			cout << "0\n";
			continue;
		}
		t1 = '#'+t1;
		int cnt = 0;
		for(int i = 1;i<=n;++i){
			build_nxt(s[i][1]);
			cnt+=kmp(t1,s[i][1],t2,s[i][2]);
		}
		cout << cnt << '\n';
	}
	return 0;
}
