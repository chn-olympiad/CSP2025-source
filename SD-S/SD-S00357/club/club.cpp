//好唐的假贪心。 
//【】调了2.5h大样例过了！！！！！ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define ll long long
#define endl '\n'
#define debug cout << "debug" << endl
using namespace std;

const int N = 1e5 + 5;
ll n, maxx = 0, cnta = 0, cntb = 0, cntc = 0;
struct node{
	int a, b, c, f = 0;
}s[N];

bool cmpa(node x, node y){
	return min(x.a - x.b, x.a - x.c) > min(y.a - y.b, y.a - y.c);
}
bool cmpb(node x, node y){
	return min(x.b - x.a, x.b - x.c) > min(y.b - y.a, y.b - y.c);
}
bool cmpc(node x, node y){
	return min(x.c - x.b, x.c - x.a) > min(y.c - y.b, y.c - y.a);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		maxx = 0, cnta = cntb = cntc = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			if(s[i].a >= s[i].b && s[i].a >= s[i].c){
				s[i].f = 1;
			}
			else if(s[i].b >= s[i].a && s[i].b >= s[i].c) s[i].f = 2;
			else if(s[i].c >= s[i].a && s[i].c >= s[i].b) s[i].f = 3;
		}
		for(int i = 1; i <= n; i++){
			if(s[i].f == 1){
				cnta++, maxx += s[i].a;
			}else if(s[i].f == 2){
				cntb++, maxx += s[i].b;
			}else{
				cntc++, maxx += s[i].c;
			}
		}
		if(cnta > n / 2){
			sort(s + 1, s + n + 1, cmpa);
			for(int i = cnta; i > n / 2; i--){
				maxx -= s[i].a, cnta--;
				if((s[i].b > s[i].c && cntb <= n / 2) || cntc >= n / 2)
					maxx += s[i].b, cntb++, s[i].f = 2;
				else maxx += s[i].c, cntc++, s[i].f = 3;
			}
		}
		if(cntb > n / 2){
			sort(s + 1, s + n + 1, cmpb);
			for(int i = cntb; i > n / 2; i--){
				maxx -= s[i].b, cntb--;
				if((s[i].a > s[i].c && cnta <= n / 2) || cntc >= n / 2){
					maxx += s[i].a, cnta++, s[i].f = 1;
				}else{
					maxx += s[i].c, cntc++, s[i].f = 3;
				}
			}
		}
		if(cntc > n / 2){
			sort(s + 1, s + n + 1, cmpc);
			for(int i = cntc; i > n / 2; i--){
				maxx -= s[i].c, cntc--;
				if((s[i].a > s[i].b && cnta <= n / 2) || cntb >= n / 2)
					maxx += s[i].a, cnta++, s[i].f = 1;
				else maxx += s[i].b, cntb++, s[i].f = 32;
			}
		}
		cout << maxx << endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
