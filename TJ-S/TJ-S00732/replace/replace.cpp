#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int P = 13 , MAXL = 5e6 + 5;
int p[MAXL] = {1};
int n , q;
char s1[MAXL] , s2[MAXL];
int h1[MAXL] , h2[MAXL];
unordered_map < int , unordered_map<int , int> > H;

int gethash(char *s , int L){
	int has = 0;
	for (int i = 1 ; i <= L ; i ++) has = has * P + s[i];
	return has;
}

signed main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (int i = 1 ; i < MAXL ; i ++) p[i] = p[i - 1] * P;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i ++){
		cin >> (s1 + 1) >> (s2 + 1);
		int L = strlen(s1 + 1);
		H[gethash(s1 , L)][gethash(s2 , L)] ++;
	}
	int L , has1 , has2 , ans;
	while (q --){
		ans = 0;
		cin >> (s1 + 1) >> (s2 + 1);
		L = strlen(s1 + 1);
		for (int i = 1 ; i <= L ; i ++)
			h1[i] = h1[i - 1] * P + s1[i] , h2[i] = h2[i - 1] * P + s2[i];
			
		for (int l = 1 ; l <= L ; l ++){
			if (h1[l - 1] != h2[l - 1]) break;
			for (int r = L ; r >= l ; r --){
				if (h1[L] - h1[r] * p[L - r] != h2[L] - h2[r] * p[L - r]) break;
				has1 = h1[r] - h1[l - 1] * p[r - l + 1] , has2 = h2[r] - h2[l - 1] * p[r - l + 1];
				if (H.count(has1) && H[has1].count(has2)) ans += H[has1][has2];//cout << l << ' ' << r << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
