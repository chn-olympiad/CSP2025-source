#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const int L = 5e6 + 7;

int n, q, len[N], sum, ans;
string s1[N], s2[N];
string inp1[N], inp2[N];

void solve1(){
	for(int p = 1; p <= q; p++){
		ans = 0;
		for(int i = 0; i < inp1[p].size(); i++){
			for(int j = 1; j <= n; j++){
				if(i + len[j] <= inp1[p].size() && inp1[p].substr(i, len[j]) == s1[j]){
					string tmp = inp1[p].substr(0, i);
					tmp.append(s2[j]);
					if(i + len[j] < inp1[p].size()) tmp.append(inp1[p].substr(i + len[j]));
					if(tmp == inp2[p]) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}

int findB(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'b') return i;
	}
	return 0;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>s1[i]>>s2[i];
		len[i] = s1[i].size();
		int dis = findB(s2[i]) - findB(s1[i]) + L;
		a[i].lf = findB(s1[i]);
		a[i].len = len[i];
		a[i].ne = h[dis];
		h[dis] = i;
	}
	for(int i = 1; i <= q; i++){
		cin>>inp1[i]>>inp2[i];
		sum += inp1[i].size();
	}
	if(sum <= 2e3){
		solve1();
		return 0;
	}
	return 0;
} 
