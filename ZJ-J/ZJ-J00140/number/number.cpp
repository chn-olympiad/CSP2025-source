#include <bits/stdc++.h> // 100pts
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 5;
string s;
int a[N], top;

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	if (s.size() == 1) {
		cout << s;
		return 0;
	}
	
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++top] = s[i] - '0';
	}
	
	sort(a + 1, a + 1 + top, cmp);
	
	for (int i = 1; i <= top; ++i)
		cout << a[i];
	
	cout << endl;
	return 0;
}
/*
我要上迷惑行为大赏！！！！！
《火车头，启动！》 
算了不弄了（1=更重要 
#Shang4Shan3Ruo6Shui4 加密密码 
*/
