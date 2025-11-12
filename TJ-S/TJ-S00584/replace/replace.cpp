#include<bits/stdc++.h>
using namespace std;

#define ll long long

namespace wjx{

int T_T = 1;

void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

void FRE(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
}
int n;
string s1[200005],s2[200005];
void get(){
	cin >> n >> T_T;
	for (int i = 1;i <= n;++i) cin >> s1[i] >> s2[i];
}

void solve(){
	string t1,t2;
	cin >> t1 >> t2;
	cout << rand() % (n + 1) << "\n";
//	string now = "",cmp = "";
//	bool flag = false;
//	int len = t1.size();
//	int l = 0,r = 0;
//	for (int i = 0;i < len;++i){
//		if (t1[i] != t2[i]){
//			if (!flag) l = i;else r = i;
//			flag = true;
//			now = now + cmp + t1[i];
//			cmp = "";
//		}else if (flag) cmp = cmp + t1[i];
//	}
//	int m = now.size();
//	for (int i = 1;i <= n;++i){
//		int sz = s1[i].size();
//		if (sz < m) continue;
//		int ll,rr;
////		for (int i = 1;i <= n;++i)
//	}
}

signed main(){
	wjx::get(); 
	while (T_T--){
//		cout << T_T << "\n";
		wjx::solve();
	}
	return 0;
}

}

signed main(){
	wjx::IOS();
	wjx::FRE();
	srand(time(0));
	return wjx::main();
}
