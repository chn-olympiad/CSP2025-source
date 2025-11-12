#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;
const int INF = 1145141919; // 并没有用 

int n, Q;
pair<string, string> pat[MAX];
string s1, s2;

string cut(string s, int beg, int end) {
	string res = "";
	for(int i = beg; i < end; i++) {
		res += s[i];
	}
	return res;
}

string replace(string s, string t1, string t2) {
	string res = cut(s, 0, s.find(t1));
	res += t2 + cut(s, s.find(t1) + t2.length(), s.length());
	return res;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) {
		cin >> pat[i].first >> pat[i].second;
	}	
	
	while(Q--) {
		cin >> s1 >> s2;
		
		// 判长度 
		if (s1.length() != s2.length()) {
			cout << 0 << '\n';
			continue;
		}
		
		// 判存在 
		bool flag = false;
		for(int i = 1; i <= n; i++) if (s1.find(pat[i].first) != -1)
			flag = true;
		if (!flag)  {
			cout << 0 << "\n";
			continue;
		}
		
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			string pre = "", tmp = s1;
			while(tmp.find(pat[i].first) != -1) {
				if (pre + replace(tmp, pat[i].first, pat[i].second) == s2)
					ans++;
				pre = cut(tmp, 0, tmp.find(pat[i].first) + pat[i].first.length());
				tmp = cut(tmp, 
					tmp.find(pat[i].first) + pat[i].first.length(), tmp.length());
			}
		} 
		
		cout << ans << '\n';
	}
	
	return 0;
}

/*
两种不同
一是位置，二是替换单元
那么就对于每一个替换单元
搜有几个位置 

对于每一个单元p
s1_pre = "" 
while(s1.find(p.1))
	if (s1_pre + s1.replace(p.1, p.2) == s2)
		ans++
	s1_pre = cut(s1, 0, s1.find(p.1) + p1.length())
	s1 = cut(s1, s1.find(p.1) + p.1.length(), s1.length())
----- 

17:10 start
我好逊啊

位子在一排的最左边
再左边是监考老师
囍 

我一眼就看出了这题是 自动AC机（嘻）
但是板子忘掉了

尝试现推
哦
还要推kmp 

string find() 的算法是什么？ 

先写个暴力出来 

18：00
暴力写完了...
我真的是太逊了
可能只是饿了而已
先吃个面包再说

我是 NOIP 吃面包记的忠实读者！ 
*/

