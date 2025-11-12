#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[10] = {};
const int mod = 998244353;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char ch = getchar();
	while(!islower(ch) && !isdigit(ch)) ch = getchar();
	while(islower(ch) || isdigit(ch)) {
		if(isdigit(ch))	num[ch ^ 48]++;
		ch = getchar();
	}
	for(int i = 10; i; i--)
		for(int j = 0; j < num[i - 1]; j++) putchar(i + 47);

    return 0;
}
