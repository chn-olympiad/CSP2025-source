#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int MaxN = 2e5+10;
Int n, q;
struct uu{
	string s;
};
uu a[MaxN];
uu b[MaxN];
string gg(string a, Int s, string b){
	for(Int i = s; i < s+b.size(); i ++){
		a[i] = b[i-s];
	}
	return a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//string a, b;
	//Int c;
	//cin >> a >> b >> c;
	//cout << gg(a,c,b);
	scanf("%lld %lld", &n, &q);
	for(Int i = 1; i <= n; i ++){
		cin >> a[i].s >> b[i].s;
	}
	while(q --){
		string qa, qb;
		cin >> qa >> qb;
		if(qa.size() != qb.size()){
			printf("0\n");
			continue;
		}
		Int ans = 0;
		for(Int i = 1; i <= n; i ++){
			for(Int j = 0; j < qa.size()-a[i].s.size(); j ++){
				if(gg(qa,j,a[i].s) == qa && gg(qa,j,b[i].s) == qb){
					ans ++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

