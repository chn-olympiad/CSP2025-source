#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

typedef long long LL;

inline LL read() { LL x = 0, f = 1; char ch; while(!isdigit(ch = getchar())) if (ch == '-') f = -1; do x = (x << 3) + (x << 1) + (ch ^ 48); while(isdigit(ch = getchar())); return x * f; }

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n = read(), m = read(), xiao_R, num = n * m;
	vector<int> s(num + 1, -1);
	
	xiao_R = s[1] = read();
	for (int i = 2; i <= num; i++) s[i] = read();
	sort(s.begin() + 1, s.end(), [](int a, int b){
		return a > b;
	});
	
//	int pos = upper_bound(s.begin() + 1, s.end(), xiao_R) - s.begin() - 1; debug(pos);
	int pos; for (int i = 1; i <= num; i++) if (s[i] == xiao_R) pos = i; // debug(pos);//
	
	int unit_1 = (pos + 2 * n - 1) / (2 * n), unit_2 = pos % (2 * n);
	
	int lie = 2 * unit_1 - 1 + (unit_2 <= n ? 0 : 1);
	int hang = (unit_2 > n ? n - ((unit_2 - n) - 1) : unit_2);
	
	cout << lie << ' ' << hang << '\n';
	
	return 0;
}