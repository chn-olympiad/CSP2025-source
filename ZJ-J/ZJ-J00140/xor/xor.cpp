#include <bits/stdc++.h>
#define int long long
#define make_pr make_pair
#define endl '\n'
using namespace std;
const int N = 5e5 + 5;

struct Node {
	int lt, rt;
};

int n, k, a[N];
int maxn = -114514;
queue <Node> q; // 存储每一个可行的左右端点，最后判断去重 

int read_x;
bool read_flag;
char read_ch;
inline int read() {
	read_x = 0, read_flag = false;
	read_ch = getchar();
	
	while (read_ch < 48 || read_ch > 57) {
		if (read_ch == 45)
			read_flag = true;
		read_ch = getchar();
	}
	
	while (read_ch >= 48 && read_ch <= 57) {
		read_x = (read_x << 3) + (read_x << 1) + (read_ch ^ 48);
		read_ch = getchar();
	}
	
	return read_flag ? -read_x : read_x;
}

void Subtask4_5() {
	int num = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 1)
			num++;
	}
	
	if (k == 1)
		cout << num << endl;
	else
		cout << n - num << endl;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read();
	k = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
//  读入	
	if (k == 1) { // 数据4&5
		Subtask4_5();
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) { // 枚举左端点 
		int tmp = a[i];
		for (int j = i; j <= n; ++j) {
			if (tmp == k) {
				q.push({i, j});
//				cout << i << " " << j << endl;
				break;
			}
			tmp ^= a[j + 1];
		}
	}
	
	int len = q.size();
//	cout << len << endl;
	for (int i = 1; i <= len; ++i) {
		Node x, y;
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		if (x.lt <= y.lt && y.lt <= x.rt) // 有冲突 
			q.push(x); // 把后面这个弹出去
		else {
			q.push(x);
			q.push(y);
		}
	}

//	while (q.size()) {
//		Node u = q.front();
//		cout << u.lt << " " << u.rt << endl;
//		q.pop();
//	}
	
	cout << q.size() << endl;
	return 0;
}
/*
大样例本地过了一半，n^2预估30~40分。
今年分数不会很高吧！！！！！！！！！！ 
啊啊啊啊啊！！！！！
同机房大佬@Brute_Force(uid=995899一定要让我过啊！！！！！！！！！！！！！！！！！！！！
橙名绿钩大佬一定要保佑我啊啊啊啊啊！！！！！！！！
保佑数据很水！！！！！！！！！！ 
《僵卧孤村不自哀,Brute_Force AK IOI》！
一般现在时：Brute_Force AKs IOI
现在进行时：Brute_Force is AKing IOI
现在完成时：Brute_Force has AKed IOI
一般过去时：Brute_Force AKed IOI
过去完成时：Brute_Force had AKed IOI
一般将来时：Brute_Force will AK IOI
过去进行时：Brute_Force was AKing IOI
一句话：Brute_Force AK IOI!!!!!!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
*/
