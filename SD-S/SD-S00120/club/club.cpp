#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio> 
using namespace std;
const int N = 200000 + 10;
struct node{
	int a, b, c, mx = 0;
} s[N];
bool cmp(node x, node y){
	if (x.mx != y.mx) return x.mx < y.mx;
	if (x.mx == 1) return x.a > y.a;
	if (x.mx == 2) return x.b > y.b;
	if (x.mx == 3) return x.c > y.c;
}
int T, n;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			int mxx = max({s[i].a, s[i].b, s[i].c});
			if (mxx == s[i].a) s[i].mx = 1;
			if (mxx == s[i].b) s[i].mx = 2;
			if (mxx == s[i].c) s[i].mx = 3;
		}
		
		int ans = 0, cnt = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++){
			if (s[i].mx == 1 && cnt <= n / 2){
				cnt++;
				ans += s[i].a;
			}
			else if (s[i].mx == 2 && cnt1 <= n / 2){
				cnt1++;
				ans += s[i].b;
			}
			else if (s[i].mx == 3 && cnt2 <= n / 2){
				cnt2++;
				ans += s[i].c;
			}
			else{
				if (s[i].mx == 1){
					ans += max(s[i].b, s[i].c);
				}
				if (s[i].mx == 2){
					ans += max(s[i].a, s[i].c);
				}
				if (s[i].mx == 3){
					ans += max(s[i].a, s[i].b);
				}
			}
		}
		cout << ans << endl;

	}
	return 0;
}

