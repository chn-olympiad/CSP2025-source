#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node{
	int ls1, ls2, ls3;
}num[N];
int read(){
	int s = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return s;
}
bool cmp1(node a, node b){
	return a.ls1 > b.ls1;
}
bool cmp2(node a, node b){
	return a.ls2 > b.ls2;
}
bool cmp3(node a, node b){
	return a.ls3 > b.ls3;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, n, m, cnta, cntb, cntc;
	long long suma, sumb, sumc, ma;
	cin >> T;
	while(T--){
		n = read();
		m = n / 2;
		suma = 0;
		sumb = 0;
		sumc = 0;
		ma = 0;
		cnta = 0;
		cntb = 0;
		cntc = 0;
		for(int i = 1, a, b, c; i <= n; i++){
			a = read();
			b = read();
			c = read();
			if(a >= b && a >= c){
				ma += a;
				cnta++;
			}
			else if(b >= a && b >= c){
				ma += b;
				cntb++;
			}
			else{
				ma += c;
				cntc++;
			}
			suma += a;
			sumb += b;
			sumc += c;
			num[i].ls1 = max(b, c) - a;
			num[i].ls2 = max(a, c) - b;
			num[i].ls3 = max(a, b) - c;
		}
		if(cnta <= m && cntb <= m && cntc <= m){
			cout << ma << "\n";
			continue;
		}
		sort(num + 1, num + n + 1, cmp1);
		for(int i = 1; i <= m; i++){
			suma += num[i].ls1;
		}
		sort(num + 1, num + n + 1, cmp2);
		for(int i = 1; i <= m; i++){
			sumb += num[i].ls2;
		}
		sort(num + 1, num + n + 1, cmp3);
		for(int i = 1; i <= m; i++){
			sumc += num[i].ls3;
		}
		cout << max(max(suma, sumb), sumc) << "\n";
	}
	return 0;
}
//14:46 over, wait a minute, no, that's not correct;
//14.52 oh, I find the preblem, but it's still incorrect;
//14.55 oh I went along the wrong way;
//15.05 okay I repaired the bug, let's try;
//15.08 truly over
