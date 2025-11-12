// 张洛川 高新第二初级中学 SN-J00375 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 +  10;
string s;
int a[N];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	memset(a, -1, sizeof(a));
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size(), ind = 1;
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[ind] = s[i] - '0';
			ind++;
		}
	}
	sort(a+1, a+ind, cmp);
	if (a[1] == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i < ind; i++) {
		if (a[i] != -1) {
			printf("%d", a[i]);
		}
	}
	printf("\n");
	
	
	return 0;
}
