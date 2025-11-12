#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
bool Begin;
const int N = 2e5 + 10, M = 5e6 + 10, W = 26;
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
		  f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
	  write(x / 10);
	putchar(x % 10 + '0');
}
int n, q;
ll ans[N];
bool vis[M];
char s[M], t[M];
vector<int> V[M];
vector<pair<int, int>> E[M];
vector<pair<int, pair<int, int>>> Q[M];
unordered_map<int, int> mp[M];
class ACAM{
public:
	int cnt;
	struct Node{
		int son[W];
		int dep, fail;
	}tr[M];
	inline int ins(char *s){
		int x = 0, len = strlen(s + 1);
		for(int i = 1; i <= len; ++i){
			int c = s[i] - 'a';
			if(!tr[x].son[c])
			  tr[x].son[c] = ++cnt;
			x = tr[x].son[c];
		}
		return x;
	}
	inline void build(){
		queue<int> q;
		for(int i = 0; i < W; ++i){
			if(tr[0].son[i]){
				q.push(tr[0].son[i]);
				tr[tr[0].son[i]].dep = 1;
			}
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0; i < W; ++i){
				if(tr[u].son[i]){
					tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
					tr[tr[u].son[i]].dep = tr[u].dep + 1;
					q.push(tr[u].son[i]);
				}
				else
				  tr[u].son[i] = tr[tr[u].fail].son[i]; 
			}
		}
//		for(int i = 1; i <= cnt; ++i){
//			if((int)V[i].size() > 1)
//			  cerr << V[i].size() << ' ';
//		}
//		cerr << '\n';
	}
}T;
inline bool sp(char* s){
	int len = strlen(s + 1), na = 0, nb = 0;
	for(int i = 1; i <= len; ++i){
		if(s[i] != 'a' && s[i] != 'b')
		  return 0;
		if(s[i] == 'a')
		  ++na;
		if(s[i] == 'b')
		  ++nb;
		if(nb > 1)
		  return 0;
	}
	return (na == len - 1 && nb == 1);
}
bool End;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int mx = 0;
	bool flagB = 1;
	n = read(), q = read();
	for(int i = 1; i <= n; ++i){
		scanf("%s%s", s + 1, t + 1);
		if(sp(s) && sp(t) && flagB){
			int x = 0, y = 0, len = strlen(s + 1);
			for(int i = 1; i <= len; ++i){
				if(s[i] == 'b')
				  x = i;
				if(t[i] == 'b')
				  y = i;
			}
			mx = max(mx, len);
			E[len].push_back({x, y});
//			cerr << x << ' ' << y << '\n';
		}
		else
		  flagB = 0;
		V[T.ins(s)].push_back(T.ins(t));
	}
//	cerr << flagB << '\n';
	if(!flagB)
	  T.build();
	for(int now = 1; now <= q; ++now){
		ll sum = 0;
		scanf("%s%s", s + 1, t + 1);
		int x = strlen(s + 1), y = strlen(t + 1);
		if(x != y){
			puts("0");
			continue;
		}
		int l = x, r = 0;
		for(int i = 1; i <= x; ++i)
		  if(s[i] != t[i])
		    l = min(l, i), r = max(r, i);
		if(sp(s) && sp(t) && flagB){
			int a = strlen(s + 1);
			int x = (s[l] == 'b' ? l : r), y = l ^ r ^ x;
			for(int i = l; i >= 1; --i)
			  Q[a - i + 1].push_back({now, {x - i + 1, y - i + 1}});
			mx = max(mx, a);
			continue;
		}
		int a = 0, b = 0;
		for(int i = 1; i <= r - 1; ++i){
			a = T.tr[a].son[s[i] - 'a'];
			b = T.tr[b].son[t[i] - 'a'];
		}
		for(int i = r; i <= x; ++i){
			int len = i - l + 1;
			a = T.tr[a].son[s[i] - 'a'];
			b = T.tr[b].son[t[i] - 'a'];
			for(int i = b; T.tr[i].dep >= len; i = T.tr[i].fail)
			  vis[i] = 1;
			for(int i = a; T.tr[i].dep >= len; i = T.tr[i].fail)
		      for(auto j : V[i])
		        sum += vis[j];
			for(int i = b; T.tr[i].dep >= len; i = T.tr[i].fail)
			  vis[i] = 0;
		}
		write(sum);
		putchar('\n');
	}
	if(flagB){
		for(int i = 1; i <= mx; ++i){
			for(auto t : E[i])
			  ++mp[t.fi][t.se];
			for(auto t : Q[i])
			  ans[t.fi] += mp[t.se.fi][t.se.se];
		}
		for(int i = 1; i <= q; ++i){
			write(ans[i]);
			putchar('\n');
		}
		return 0;
	}
//	cerr << 1.0 * (&Begin - &End) / 1024.0 / 1024.0;
	return 0;
}