// SN-J00858
// TYZ
// csy
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
string s;
vector<int> a;
void sol(){
	cin>>s;
	for(char c:s) if(c>='0'&&c<='9') a.push_back(c-48);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(int i:a) cout<<i;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ii();
//	int TT;for(cin>>TT;TT--;)
	sol();
	return 0;
}
