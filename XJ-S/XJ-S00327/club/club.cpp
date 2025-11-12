#include<bits/stdc++.h>
using namespace std;
template <typename type>
inline void read(type &x){
	x = 0;
	static bool flag;
	flag = 0;
	char ch = getchar();
	while (!isdigit(ch)){
		flag = ch == '-';
		ch = getchar();
	} while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	} flag ? x = -x : 0;
} const int MAXN = 1e5 + 5;
struct node{
	int a, b, c, Max, Mid, Min, abs_of_Max_and_Mid, Maxc, Midc, Minc;
	void in(){
		read(a);
		read(b);
		read(c);
		solve();
	} void solve(){
		if (a > b){
			if (b > c) write(a, b, c, 1, 2, 3);
			else {
				if (a > c) write(a, c, b, 1, 3, 2);
				else write(c, a, b, 3, 1, 2);
			}
		} else {
			if (b > c){
				if (a > c) write(b, a, c, 2, 1, 3);
				else write(b, c, a, 2, 3, 1);
			} else write(c, b, a, 3, 2, 1);
		}
	} void write(int wa, int wb, int wc, int wac, int wbc, int wcc){
		Max = wa;
		Maxc = wac;
		Mid = wb;
		Midc = wbc;
		Min = wc;
		Minc = wcc;
		abs_of_Max_and_Mid = Max - Mid;
	}
}; node l[MAXN];
bool cmp(node a, node b){
	if (a.abs_of_Max_and_Mid > b.abs_of_Max_and_Mid) return 1;
	return 0;
} int T, n, ans, cnt[4];
void clean(){
	ans = 0;
	memset(cnt, 0, sizeof(cnt));	
} void solve(){
	clean();
	int limit_of_n = n / 2;
	for (int i = 0; i < n; i++){
		if (cnt[l[i].Maxc]++ < limit_of_n) ans += l[i].Max;
		else ans += l[i].Mid;
	} printf("%d\n", ans);
} int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
	while (T--){
		read(n);
		for (int i = 0; i < n; i++){
			l[i].in();
		} sort(l, l + n, cmp);
		solve();
	} return 0;
}

