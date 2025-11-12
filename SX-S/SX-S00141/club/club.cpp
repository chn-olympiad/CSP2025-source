#include <bits/stdc++.h>
using namespace std;
#define P pair<int,char>
#define P1 pair<int,pair<int,int> >

struct node {
	int a, b, c;
};
priority_queue<P> que;
priority_queue<P1, vector<P1>, greater<P1> > quea, queb, quec;
int n, A, B, C, book[500005], m;
node t[500005];

bool cmp(node x, node y) {
	return x.a < y.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> m;
	while (m--) {
		cin >> n;
		int s = 0;
		for (int i = 1; i <= n; i++) {
			cin >> A >> B >> C;
			t[i].a = A, t[i].b = B, t[i].c = C;
		}
		for (int i = 1; i <= n; i++) {
			que.push(make_pair(t[i].a, 'a'));
			que.push(make_pair(t[i].b, 'b'));
			que.push(make_pair(t[i].c, 'c'));
			char ch = que.top().second;
			if (ch == 'a') {
				s += que.top().first ;
				quea.push(make_pair(t[i].a, make_pair(t[i].b, t[i].c) ) );
			}
			if (ch == 'b') {
				s += que.top().first ;
				queb.push(make_pair(t[i].b, make_pair(t[i].a, t[i].c) ) );
			}
			if (ch == 'c') {
				s += que.top().first;
				quec.push(make_pair(t[i].c, make_pair(t[i].a, t[i].b) ) );
			}
			while (que.size())
				que.pop();
		}
		while (quea.size() > n / 2) {
			int bb = quea.top().second.first, cc = quea.top().second.second;
			s -= quea.top().first;
			quea.pop();
			if (bb > cc) {
				s += bb;
			} else {
				s += cc;
			}
		}
		while (queb.size() > n / 2) {
			int aa = queb.top().second.first, cc = queb.top().second.second;
			s -= queb.top().first;
			queb.pop();
			if (aa > cc) {
				s += aa;
			} else {
				s += cc;
			}
		}
		while (quec.size() > n / 2) {
			int aa = quec.top().second.first, bb = quec.top().second.second;
			s -= quec.top().first;
			quec.pop();
			if (aa > bb) {
				s += aa;
			} else {
				s += bb;
			}
		}
		cout << s << '\n';
		while (quea.size())
			quea.pop();
		while (queb.size())
			queb.pop();
		while (quec.size())
			quec.pop();
	}
	return 0;
}
