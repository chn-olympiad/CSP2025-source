#include <bits/stdc++.h>
using namespace std;
#define itn int
#define tin int
#define tni int
#define nit int
#define nti int
#define fro for
#define orf for
#define ofr for
#define rfo for
#define rof for
#define inc cin
#define icn cin
#define nci cin
#define nic cin
#define cni cin
int n;
bool a[500005];
long long t, f;
bool k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] == 1) t++;
		else f++;
	}
	if(k) {
		cout << t << endl;
	} else {
		cout << t/2 + f << endl;;
	}
	return 0;
}
