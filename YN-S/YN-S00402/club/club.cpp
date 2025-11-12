#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e5 + 5;

set<pair<int, int>, greater<pair<int, int> > > stt[4]; //三个部门分别选最满意的n/2名的分数
struct clubb {
	int a, b, c; //分别在a,b,c部门的满意度
} clu[N];

bool boo[4];//哪个部门一直为0
bool vis[N];//哪些部门已经被选了
int main () {
	IOS
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	vector<ll> anss;

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		ll summ = 0;

		for (int i = 1; i <= n; i++) {

			cin >> clu[i].a >> clu[i].b >> clu[i].c;

			if (boo[1] == 0 && clu[i].a != 0)
				boo[1] = 1;

			if (boo[2] == 0 && clu[i].b != 0)
				boo[2] = 1;

			if (boo[3] == 0 && clu[i].c != 0)
				boo[3] = 1;
			stt[1].insert({clu[i].a, i}); //部门A
			stt[2].insert({clu[i].b, i}); //部门B
			stt[3].insert({clu[i].c, i}); //部门C
		}

		int cnt = 0; //数数有几个非零

		for (int i = 1; i <= 3; i++) {

			if (boo[i])
				cnt++;
		}

		if (cnt == 1) {
			int idxx = 0;

			for (int i = 1; i <= 3; i++) {

				if (boo[i])
					idxx = i;
			}

			int cnt = 1;

			for (pair<int, int>ys : stt[idxx]) {
				summ += ys.first;
				cnt++;

				if (cnt > n / 2)
					break;
			}

			anss.push_back(summ);
		} else {
			anss.push_back(summ);
		}


		for (ll ys : anss) {
			cout << ys << endl;
		}
	}

	return 0;
}