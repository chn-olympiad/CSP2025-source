#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace wjx{

int T_T = 1;
string str;
vector <int> e;
void FRE(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
bool cmp(int a,int b){
	return a > b;
}
void get(){
	cin >> str;
}
void solve(){
	int n = str.size();
	for (int i = 0;i < n;++i) if ('0' <= str[i] && str[i] <= '9') e.push_back(str[i] - '0');
	sort(e.begin(),e.end(),cmp);
	n = e.size();
	for (int i = 0;i < n;++i) cout << e[i];
}

signed main(){
//	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve();
	}
	return 0;
}

}

signed main(){
//	wjx::IOS();
	wjx::FRE();
	return wjx::main();
}
/*
rp++
*/

