#include <bits/stdc++.h>
using namespace std;
string s;
long long a[15], o;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {//为数字字符
			a[s[i] - 48] ++;//桶
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], o;
bool cmp(int x, int y) return x > y;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			o++;
			a[o] = s[i] - 48;
		}
	}
	stable_sort(a + 1, a + o + 1, cmp);
	//stable_sort是这么拼不。？完蛋了。数据范围大的不行不用了。
	for (int i = 1; i <= o; i++) {
		cout << a[i];
	}
	return 0;
}
*/