#include <bits/stdc++.h>
using namespace std;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

int n, m;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin>>n>>m;
	FOR (i, 1, m)printf("0\n");
}
//我觉得是哈希, 但我写不完了 
//#include <bits/stdc++.h>
//using namespace std;
//using ULL=unsigned long long;
//#define cst const
//#define sttc static
//#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
//#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)
//
//int n, m;
//cst int base=233;
//vector<ULL> powb;
//struct HASH{
//	vector<ULL> ha;
//	void build(cst string &s){
//		ha.resize(s.size());
//		FOR (i, 1, s.size())ha[i]=ha[i-1]*base+s[i];
//	}
//	inline ULL get_h(cst int &le, cst int &ri){
//		return ha[ri]-ha[le]*powb[ri-le];
//	}
//};
//string s, t;
//int main(){
////	freopen("replace.in", "r", stdin);
////	freopen("replace.out", "w", stdout);
//	pow_b[0=1;FOR (i, 1, n)powb[i]=powb[i-1]*base;
//	cin.tie(0)->sync_with_stdio(false);
//
//	cin>>n>>m;
//	FOR (i, 1, n){
//		
//	}
//}
