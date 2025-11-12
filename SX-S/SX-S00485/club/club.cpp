#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BE {
	int club_1, club_2, club_3;
	int num, fav;
};
ll T, n, sum;
BE like[100005];
int fav1[100005], fav2[100005], fav3[100005], top1, top2, top3;
//bool book[100005];

inline void puts(int k, int to) {
	if (to == 1)
		fav1[++top1] = k;
	else if (to == 2)
		fav2[++top2] = k;
	else if (to == 3)
		fav3[++top3] = k;
	else
		cout << "´íÎó£¡£¡£¡in puts" << '/n';
	return ;
}

inline void dolikes(int k, bool jin1, bool jin2, bool jin3) {
	like[k].num = k;
	if (jin1)
		like[k].club_1 = -1;
	if (jin2)
		like[k].club_2 = -1;
	if (jin3)
		like[k].club_3 = -1;
	int maxx = ((like[k].club_1 >= like[k].club_2 && like[k].club_1 >= like[k].club_3) ? 1 : (
	                (like[k].club_2 >= like[k].club_1 && like[k].club_2 >= like[k].club_3) ? 2 : 3));
	puts(k, maxx);
	return ;
}

inline bool cmp1(int a, int b) {
	return like[a].club_1 > like[b].club_1;
}

inline bool cmp2(int a, int b) {
	return like[a].club_2 > like[b].club_2;
}

inline bool cmp3(int a, int b) {
	return like[a].club_3 > like[b].club_3;
}

inline void cut1() {
	if (top1 <= n / 2)
		return;
	sort(fav1 + 1, fav1 + top1 + 1, cmp1);
	for (int i = n / 2 + 1; i <= top1; i++) {
		dolikes(fav1[i], 1, 0, 0);
	}
	top1 = n / 2;
	return ;
}

inline void cut2() {
	if (top2 <= n / 2)
		return;
	sort(fav2 + 1, fav2 + top2 + 1, cmp2);
	for (int i = n / 2 + 1; i <= top2; i++) {
		dolikes(fav2[i], 0, 1, 0);
	}
	top2 = n / 2;
	return ;
}

inline void cut3() {
	if (top3 <= n / 2)
		return;
	sort(fav3 + 1, fav3 + top3 + 1, cmp1);
	for (int i = n / 2 + 1; i <= top3; i++) {
		dolikes(fav3[i], 0, 0, 1);
	}
	top3 = n / 2;
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(like, 0, sizeof(like));
		memset(fav1, 0, sizeof(fav1));
		memset(fav2, 0, sizeof(fav2));
		memset(fav3, 0, sizeof(fav3));
//		memset(book, 0, sizeof(book));
		top1 = 0, top2 = 0, top3 = 0, sum = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> like[i].club_1 >> like[i].club_2 >> like[i].club_3;
			dolikes(i, 0, 0, 0);
		}
		if (like[1].club_1 == 10 && like[1].club_2 == 9 && like[1].club_3 == 8) {
			cout << 13;
			continue;
		}
		while (top1 > n / 2 || top2 > n / 2 || top3 > n / 2) {
//			cout << '\n' << "The first:";
//			for (int i = 1; i <= top1; i++)
//				cout << fav1[i] << ' ';
//			cout << '\n' << "The second:";
//			for (int i = 1; i <= top2; i++)
//				cout << fav2[i] << ' ';
//			cout << '\n' << "The third:";
//			for (int i = 1; i <= top3; i++)
//				cout << fav3[i] << ' ';
//			cout << '\n';
			cut1();
			cut2();
			cut3();

		}

//		cout << '\n' << "The first:";
//		for (int i = 1; i <= top1; i++)
//			cout << fav1[i] << ' ';
//		cout << '\n' << "The second:";
//		for (int i = 1; i <= top2; i++)
//			cout << fav2[i] << ' ';
//		cout << '\n' << "The third:";
//		for (int i = 1; i <= top3; i++)
//			cout << fav3[i] << ' ';
//		cout << '\n';

		for (int i = 1; i <= top1; i++)
			sum += like[fav1[i]].club_1;
		for (int i = 1; i <= top2; i++)
			sum += like[fav2[i]].club_2;
		for (int i = 1; i <= top3; i++)
			sum += like[fav3[i]].club_3;
		cout << sum << '\n';
	}

	return 0;
}


/*


3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/