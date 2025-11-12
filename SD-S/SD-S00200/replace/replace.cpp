#include <bits/stdc++.h>
using namespace std;
#define getc getchar
inline long long read(){
	char c = getc() , f = 1;
	while (c > '9' || c < '0'){
		if (c == '-')f = -1;
		c = getc();
	}
	long long p = 0;
	while (c >= '0' && c <= '9'){
		p = p * 10 + c - '0';
		c = getc();
	}
	return p * f;
}
struct node{
	int val , fail , son[27];
	bool f[27];
}t[6000005];
struct _queue{
	int a[6000005] , hd , tl;
	inline void clear(){hd = tl = 0;}
	inline void push(int u){a[tl++] = u;}
	inline void pop(){hd++;}
	inline bool empty(){return hd == tl;}
	inline int front(){return a[hd];}
}qq;
int n , q , num = 0 , rt[5100005];
vector <int> v;
inline void insert(const string &s , int id , int len){
	if (!rt[id]){
		rt[id] = ++num;
		v.push_back(id);
	}
	int u = rt[id];
	for (int i = 0;i < len;++i){
		if (!t[u].son[s[i] - 'a']){
			t[u].son[s[i] - 'a'] = ++num;
			t[u].f[s[i] - 'a'] = 1;
		}
		u = t[u].son[s[i] - 'a'];
	}
	t[u].val++;
}
inline void build(){
	for (auto x : v){
		for (int i = 0;i < 27;++i){
			if (t[rt[x]].son[i]){
				qq.push(t[rt[x]].son[i]);
				t[t[rt[x]].son[i]].fail = rt[x];
			}
			else t[rt[x]].son[i] = rt[x];
			t[rt[x]].f[i] = 1;
 		}
		t[rt[x]].fail = rt[x];
	}
	while (!qq.empty()){
		int u = qq.front();
		qq.pop();
		t[u].val += t[t[u].fail].val;
		for (int i = 0;i < 27;++i){
			if (t[u].son[i]){
				t[t[u].son[i]].fail = t[t[u].fail].son[i];
				qq.push(t[u].son[i]);
			}else t[u].son[i] = t[t[u].fail].son[i];
		}
	}
}
string ss , tt;
inline int calc(string &s , string &t){
	int n = s.size() , fst = -1 , lst = 0;
	for (int i = 0;i < n;++i){
		if (s[i] != t[i]){
			if (fst == -1)fst = i;
			lst = i;
		}
	}
	if (fst != -1){
		if (lst != n - 1)s.erase(s.begin() + lst + 1 , s.end());
		s += 'z' + 1;
		for (int i = fst;i < n;++i)s += t[i];
	}
	return lst - fst + 1;
}
inline long long dfs(const string&s , int id){
	long long ans = 0;
	int u = rt[id] , n = s.size();
	if (!u)return 0;
	for (int i = 0;i < n;++i){
		ans += t[u].val;
		u = t[u].son[s[i] - 'a'];
	}
	ans += t[u].val;
	return ans;
}
signed main(){
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;++i){
		cin >> ss >> tt;
		int len = calc(ss , tt);
		insert(ss , len , ss.size());
		ss.clear();
		tt.clear();
	}
	build();
	while (q--){
		cin >> ss >> tt;
		if (ss.size() != tt.size()){
			cout << "0\n";
			continue;
		}
		int len = calc(ss , tt);
		cout << dfs(ss , len) << '\n';
		ss.clear();
		tt.clear();
	}
	return 0;
}
