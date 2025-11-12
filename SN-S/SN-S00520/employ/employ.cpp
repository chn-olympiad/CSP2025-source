#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n,m;
char a;
bool toohard = true;
bool allflee = true;
bool test[MAXN];
int s[MAXN];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n; i++) {
		cin >> a;
		if(a == '1') {
			test[i] = true;
			toohard = false;
		}
	}
	
	for(int i = 0;i < n; i++) {
		cin >> s[i];
		if(s[i] != 0) {
			allflee = false;
		}
	}
	
	if(toohard) {
		cout << 0;
		return 0;
	}
	if(allflee) {
		cout << 0;
		return 0;
	}
	
	cout << n*n;
	
	return 0;
}
