#include <bits/stdc++.h>
using namespace std;
int d, e, f[10010], t[10010], l[10010], a, n, q, as = 0, k;

int wh() {
	int ans = 0;
	k = 0;
	for (; getchar() != 'b'; ans++);
	for (k = 0; getchar() == 'a'; k++);
	return ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%d%d", &n, &q);
	getchar();
	for (int i = 1; i <= n; i++) {
		f[i] = wh();
		t[i] = wh();
		l[i] = t[i] + k + 1;
	}
	for (int i = 1; i <= q; i++) {
		d = wh();
		e = wh();
		l[0] = e + k + 1;
		as = 0;
		for (int j = 1; j <= n; j++) {
			if (d >= f[j] && l[0] - e >= l[j] - t[j] && d - e == f[j] - t[j])
				as++;
		}
		printf("%d", as);
	}

	return 0;
}

















//我服了CCF,今年收费那么高，题还那么难，心态崩了。
//第一题硬堆数据类型,测试用例都过了,但总感觉怪怪的,满不了;第二题从头到尾数据都贼大,写个最小生成树只有16分;
//第三题字符串真不会;第四题幽默面试人,看到有0血压飙升,不管怎么都放弃那你还来面试干什么啊！
//不说了，一等肯定拿不上了，中午都没睡觉，趴会得了。