#include<iostream>
#include<cstring>
#include<algorithm>
const int N = 2e5 + 10;
using tp = std::tuple<int, int, int>;
int n, q; std::string s[2][N], t[2][N];
int ct, ls[N<<6], rs[N<<6], sm[N<<6];
struct sv{
	int rt=0; std::vector<tp> a;
	void bd(int&p, int l, int r){
		if(!p) p = ++ct; sm[p] = 0;
		if(l == r) return; int md = l + r >> 1;
		bd(ls[p], l, md), bd(rs[p], md + 1, r);
	}
	void ad(int&p, int l, int r, int x){
		if(!p) p = ++ct; sm[p]++;
		if(l == r) return; int md = l + r >> 1;
		if(x <= md) ad(ls[p], l, md, x);
		else ad(rs[p], md + 1, r, x);
	}
	int qr(int p, int l, int r, int L, int R){
		if(!p) return 0;
		if(l >= L && r <= R) return sm[p];
		int md = l + r >> 1;
		if(R <= md) return qr(ls[p], l, md, L, R);
		if(L > md) return qr(rs[p], md +1, r, L, R);
		return qr(ls[p], l, md, L, R) + qr(p * 2 + 1, md + 1, r, L, R);
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> q;
	for(int i = 1; i <= n; i++){
		std::cin >> s[0][i] >> s[1][i];
		int x = s[0][i].size(), a = 0, b = 0;
	}
	for(int i = 1; i <= q; i++)
		std::cin >> t[0][i] >> t[1][i];
	
}
