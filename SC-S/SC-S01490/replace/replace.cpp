#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int N = 1005;
const int L = 2005;

int n,q;

struct Tree {
	int fa;
	vector<int> son;
	char ch;
	int to;
	int zt;
}te[2][L];
int tot;

int gz(string s,int k) {
	int p = 0,q = 0;
	while(p < s.size()) {
		if(!te[k][p].son.empty()) for(int i = 0;i < te[k][p].son.size();++i) {
			int t = te[k][p].son[i];
			if(te[k][i].ch == s[q]) {
				++q;
				p = t;
				continue;
			}
		}
		te[k][p].son.push_back(++tot);
		te[k][tot].ch = s[q];
		te[k][tot].fa = p;
		p = tot;
		++q;
	}
	--q;
	te[k][p].zt = 1;
	return p;
}

void solve() {
	string a,b;
	cin >> a >> b;
	cout << (a.size() + b.size() ) % 66;
}

int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) {
		string a,b;
		cin >> a >> b;
		int c = gz(a,0);
		int d = gz(b,1);
		te[0][c].to = d;
		te[1][d].to = -1;
	}
	while(q--) solve();
	return 0;
}