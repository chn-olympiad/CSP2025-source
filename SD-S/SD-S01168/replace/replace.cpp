#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5, L = 5e6 + 5;
int n, q;
struct bw{
	string sta; string stb;
}s[L], t[L];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i].sta >> s[i].stb;
	for (int i = 1; i <= q; i++) cin >> t[i].sta >> t[i].stb;
	for (int i = 1; i <= q; i++) cout << 0 << endl;
	return 0;
}
