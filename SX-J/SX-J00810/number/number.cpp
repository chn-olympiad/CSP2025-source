#include <bits/stdc++.h>
using namespace std;
string s;//输入数组

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	int j = 1;//记录a的序数
	int k = 0;//记录s的数字数
	for (int i = 0; i < len; i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4'
		        || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			k++;
		}
	}//记录s的数字数
	while (k--) {
		int x;//记录s被存数的序数
		int maxy = 0;//定义并还原最大值
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4'
			        || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
				if (s[i] - '0' > maxy && s[i] != 'a') {
					maxy = s[i] - '0'; //记录最大值
					x = i;//记录最大值所在序数
				}
			}//存s的最大值并记录序数
		}
		cout << maxy; //输出答案
		s[x] = 'a';//清空已输出答案
	}
	return 0;
}