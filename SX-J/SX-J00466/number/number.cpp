#include <iostream>
using namespace std;

int a[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;

	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0'] ++;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	cout << endl;

	return 0;
}

/*
log - CCF CSP-J 2025

8:31:26 开始看题
8:35:07 老师说一眼看出答案不正常，可我一眼看出答案了怎么办
8:38:51 还是在mspaint上验证了一下，开写
8:43:35 小样例全过
8:51:45 这电脑 cmd 没有 fc, powershell 的 diff 不会用怎么办
8:59:43 可恶的 Windows10 教育版，放弃调大样例了
9:02:43 freopen改好 T1完成
9:04:42 发现这个难用的IDE有文本比较功能
9:07:38 半天加载不出来977KB的输出文件和答案文件，不调了

*/