#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], book[500005], o = 1, summ, h = 1;
map<int, string>mapp;
string s1, old1, new1;

string ejz(int u) {
	string s;
	while (u) {
		if (u < 2) {
			s += 1 + 48;
			return s;
		}
		s += (u % 2) + 48;
		u /= 2;
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//第二步
		//先一个一个看，有=k的直接加，并且book数组赋特殊值
		if (a[i] == k) {
			summ++;
			book[i] = 1;//用过了
		}
		if (a[i] != 1) {
			o = 0;
		}
	}
	//5分保底！（如果我没推错的话。
	if (n <= 2 && k == 0 && o == 1) { //第一组特殊样例
		if (n == 2) { //a = {1,1}  k为0则选择[1,2]
			cout << 1;
		} else {
			//a = {1} k为0则不能选
			cout << 0;
		}
	} else {
		//第一步
		//mapp存所有数字的二进制，用string表示
		//不会直接转就除二取余二 结果+48
		for (int i = 1; i <= n; i++) {
			mapp[a[i]] = ejz(a[i]);
		}
		mapp[k] = ejz(k);
		//第三步
		//两个两个开始看，先一位一位判断出二进制，再特判是否合法
		//合法++不合法过。
		//第四步，再开始三个三个...四个四个...
		//4 2
		//a:2 1 0 3
		//book: 1 0 0 0
		//mapp:01 1 0 11
		for (int j = 2; j <= n; j++) { //长度从两个两个开始看 3
			for (int l = 2; l <= n; l++) { //循环起点3
				s1 = mapp[l - 1];//1
				for (int i = l; i <= j + l - 1 - 1; i++) { //开始异或a[i]和a[i-1]  i = 2 <4 循环三次，判断12 23 34
					new1 = mapp[a[i]];//这一次的值 11
					old1 = s1;//上一次的值 1
					s1 = "";
					long long maxx = max(old1.size(), new1.size());
					//少位数，补齐
					if (old1.size() < new1.size())//10
						for (int i = old1.size(); i < maxx; i++)
							old1 += 0 + 48;
					else if (old1.size() > new1.size())
						for (int i = new1.size(); i < maxx; i++)
							new1 += 0 + 48;
					//异或
					for (int p = 0; i < maxx; i++) {
						if (old1[i] != new1[i])
							s1 += 1 + 48;
						else
							s1 += 0 + 48;
					}
					//s1 = 01
					if (s1 == mapp[k]) { //
						for (int g = l - 1; g <= l - 1 + j - 1; g++) {
							if (book[g] == 1) {
								h = 0;
							}
						}
						if (h) {
							for (int g = l - 1; g <= l - 1 + j - 1; g++) {
								book[g] == 1;
							}
							summ++;
							break;
						}
					}
				}
			}

		}
		cout << summ;
	}
	return 0;
}