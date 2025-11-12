#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;
char str[MAXN];
int arr[MAXN], cnt = 0;
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int len;
	cin >> str;
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			arr[cnt++] = str[i] - '0';
		}
	}
	sort(arr, arr + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		cout << arr[i];
	}
	return 0;
}

