#include <bits/stdc++.h>

using namespace std;
struct clu{
	int number;
	int a, b, c;
};
struct csp{
	int num;
	int k;
};
vector<clu> t(100010);
vector<csp> ta(100010), tb(100010), tc(100010);
bool cmp1(const csp &l, const csp &r){
	return max(t[l.num].b, t[l.num].c) > max(t[r.num].b, t[r.num].c);
}
bool cmp2(const csp &l, const csp &r){
	return max(t[l.num].a, t[l.num].c) > max(t[r.num].a, t[r.num].c);
}
bool cmp3(const csp &l, const csp &r){
	return max(t[l.num].b, t[l.num].a) > max(t[r.num].b, t[r.num].a);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int u;
	cin >> u;
	while(u --){
		int n;
		long long ans = 0;
		cin >> n;
		int ca = 0, cb = 0, cc = 0;
		t.clear(), ta.clear(), tb.clear(), tc.clear();
		for(int i = 0; i < n; ++ i){
			cin >> t[i].a >> t[i].b >> t[i].c;
			if(t[i].a > t[i].b && t[i].a > t[i].c){
				ta[ca].num = i;
				ta[ca].k = t[i].a;
				ca ++;
			}
			else if(t[i].b > t[i].a && t[i].b > t[i].c){
				tb[cb].num = i;
				tb[cb].k = t[i].b;
				cb ++;
			}
			else{
				tc[cc].num = i;
				tc[cc].k = t[i].c;
				cc ++;
			}
		}
		if(ca > n / 2){
			sort(ta.begin(), ta.end(), cmp1);
			for(int i = 0; ca > n / 2; ++ i){
				if(t[ta[i].num].b > t[ta[i].num].c){
					tb[cb].k = ta[i].k, tb[cb].num = ta[i].num, cb ++;
					ta[i].k = 0, ca --;
				}
				else{
					tc[cc].k = ta[i].k, tc[cc].num = ta[i].num, cc ++;
					ta[i].k = 0, ca --;
				}
			}
		}
		if(cb > n / 2){
			sort(tb.begin(), tb.end(), cmp2);
			for(int i = 0; cb > n / 2; ++ i){
				if(t[tb[i].num].a > t[tb[i].num].c){
					ta[ca].k = tb[i].k, ta[ca].num = tb[i].num, ca ++;
					tb[i].k = 0, cb --;
				}
				else{
					tc[cc].k = tb[i].k, tc[cc].num = tb[i].num, cc ++;
					tb[i].k = 0, cb --;
				}
			}
		}
		if(cc > n / 2){
			sort(tc.begin(), tc.end(), cmp3);
			for(int i = 0; cc > n / 2; ++ i){
				if(t[tc[i].num].a > t[tc[i].num].b){
					ta[ca].k = tc[i].k, ta[ca].num = tc[i].num, ca ++;
					tc[i].k = 0, cc --;
				}
				else{
					tb[cb].k = tc[i].k, tb[cb].num = tc[i].num, cb ++;
					tc[i].k = 0, cc --;
				}
			}
		}
		for(int i = 0; i < ca; ++ i) ans += ta[i].k;
		for(int i = 0; i < cb; ++ i) ans += tb[i].k;
		for(int i = 0; i < cc; ++ i) ans += tc[i].k;
		cout << ans << endl;
	}
	return 0;
}
