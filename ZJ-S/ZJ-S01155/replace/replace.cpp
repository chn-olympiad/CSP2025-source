#include<bits/stdc++.h>
using namespace std;
#define IO cin.tie(0);cout.tie(0);

const int INF = 0x3f3f3f3f;
const int N = 3e4+10;

struct node{
	int len;
	char name;
	int val;
	map<char, int> nxt;
	int fair;
};

int n,q;
vector<node> ta;
vector<node> tb;

void make_fair(vector<node>& t, int x, int dad){
	if (x != 0){
		for (int i = t[dad].fair; i != 0; i = t[i].fair){
			if (t[i].nxt[t[x].name-'a'] != 0){
				t[x].fair = t[i].nxt[t[x].name-'a'];
				break; 
			}
		}
	}
	if (t[x].val == 0){
		for (auto a : t[x].nxt){
			make_fair(t, a.second, x);
		}
	}
}

int main(){
	IO;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	ta.push_back(node());
	ta.push_back(node());
	for (int i = 1; i<=n; i++){
		string a,b;
		cin>>a>>b;
		int x = 0;
		for (int i = 0; i<a.size(); i++){
			if (ta[x].nxt[a[i]-'a'] == 0){
				ta[x].nxt[a[i]-'a'] = ta.size();
				ta.push_back(node());
				ta[ta.size()-1].name = a[i];
			}
			x = ta[x].nxt[a[i]-'a'];
		}
		int y = 0;
		for (int i = 0; i<b.size(); i++){
			if (tb[y].nxt[b[i]-'a'] == 0){
				tb[y].nxt[b[i]-'a'] = tb.size();
				tb.push_back(node());
				tb[tb.size()-1].name = b[i];
			}
			y = tb[y].nxt[b[i]-'a'];
		}
		ta[x].val = y;
		ta[x].len = a.size();
		cout << 10 << ' ';
	}
	make_fair(ta, 0, 0);
	make_fair(ta, 0, 0);
	while (q--){
		int ans = 0;
		string a,b;
		cin>>a>>b;
		int x=0;
		int y=0;
		for (int i = 0; i<a.size(); i++){
			if (ta[x].val != 0 && ta[x].val == y){
				ans += 1;
			}
			if (ta[x].nxt[a[i]-'a'] != 0) x = ta[x].nxt[a[i]-'a'];
			else x = ta[x].fair;
			if (tb[y].nxt[b[i]-'a'] != 0) y = tb[y].nxt[b[i]-'a'];
			else y = tb[y].fair;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
