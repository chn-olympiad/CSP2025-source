#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, n, firn = 1, secn = 1, thrn = 1;
long long sum;

struct Node{
	int one, two, three, zy[3];
} a[100005], first[100005], second[100005], third[100005];

bool cmp1(Node x, Node y) {
	return x.one > y.one;
}
bool cmp2(Node x, Node y) {
	return x.two > y.two;
}
bool cmp3(Node x, Node y) {
	return x.three > y.three;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		sum = 0;
		firn = 1, secn = 1, thrn = 1;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> a[i].one >> a[i].two >> a[i].three;
			if (a[i].one >= a[i].two && a[i].one >= a[i].three) {
				a[i].zy[0] = 1;
				if (a[i].two >= a[i].three) a[i].zy[1] = 2, a[i].zy[2] = 3;
				else a[i].zy[1] = 3, a[i].zy[2] = 2;
				
				first[firn] = a[i];
				firn++;
			} else if (a[i].two >= a[i].one && a[i].two >= a[i].three) {
				a[i].zy[0] = 2;
				if (a[i].one >= a[i].three) a[i].zy[1] = 1, a[i].zy[2] = 3;
				else a[i].zy[1] = 3, a[i].zy[2] = 1;
				
				second[secn] = a[i];
				secn++;
			} else {
				a[i].zy[0] = 3;
				if (a[i].two >= a[i].one) a[i].zy[1] = 2, a[i].zy[2] = 1;
				else a[i].zy[1] = 1, a[i].zy[2] = 2;
				
				third[thrn] = a[i];
				thrn++;
			}
		}
		firn--, secn--, thrn--;
		sort(first + 1, first + firn + 1, cmp1);
		sort(second + 1, second + secn + 1, cmp2);
		sort(third + 1, third + thrn + 1, cmp3);
		
		if (firn > n / 2) {
			for (int i = firn;i > n / 2;i--) {
				if(first[i].zy[1] == 2) {
					secn++;
					second[secn] = first[i];
				} else {
					thrn++;
					third[thrn] = first[i];
				}
				firn--;
			}
		} else if (secn > n / 2) {
			for (int i = secn;i > n / 2;i--) {
				if(second[i].zy[1] == 1) {
					firn++;
					first[firn] = second[i];
				} else {
					thrn++;
					third[thrn] = second[i];
				}
				secn--;
			}
		} else {
			for (int i = thrn;i > n / 2;i--) {
				if(third[i].zy[1] == 2) {
					secn++;
					second[secn] = third[i];
				} else {
					firn++;
					first[firn] = third[i];
				}
				thrn--;
			}
		} 
		
		for (int i = 1;i <= firn;i++) {
			sum += first[i].one;
		}
		for (int i = 1;i <= secn;i++) {
			sum += second[i].two;
		}
		for (int i = 1;i <= thrn;i++) {
			sum += third[i].three;
		}
		
		cout << sum << endl;
		
	}
	return 0;
}
