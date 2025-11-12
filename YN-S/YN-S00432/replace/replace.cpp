#include <bits/stdc++.h>
using namespace std;

class Str {
	public:
		string a;
		string b;
		Str(string a, string b) {
			this->a = a;
			this->b = b;
		}
};

void process(vector<string> &v, int pos, string s, string str) {
	if (pos >= s.size()) {
		v.push_back(str);
		return;
	}
//	if (str.size() == 0) {

//	}{
	process(v, pos + 1, s, str + s[pos]);
	process(v, pos + 1, s, str);

}

int main() {
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<Str> vs;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		Str s = Str(a, b);
		vs.push_back(s);

	}
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<string> v;
		vector<string> v1;

		process(v, 0, s1, "");
		process(v1, 0, s2, "");
		int num = 0;
		for (string ii : v) {
			cout << ii << " ";
		}
		cout << endl;
		for (string ii : v1) {
			cout << ii << " ";
		}
		cout << endl;
		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (v[j] == vs[k].a) {
//					cout << v[j] << "---" << endl;
					vector<string> tv = v;

					tv[j] = vs[k].b;
//					cout << tv[j] << "+++" << endl;
					for (string ii : tv) {
//						cout << ii << "***";
					}
					if (tv == v1) {
						num++;
					}
					tv.clear();
				}
			}
		}
//		for (string i : v) {
//			cout << i << " " << endl;
//		}

		cout << num << endl;
	}

//	fclose(stdin);
//	fclose(stdout);
	return 0;
//	cout << LONG_LONG_MAX << endl;
}

