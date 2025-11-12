#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1001000;
string s;
ll a[N],g;
inline void solve(){
	g=0;
	getline(cin,s);
	ll slen=s.size();
	for(int i=0;i<slen;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++g]=s[i]-'0';
	sort(a+1,a+g+1);
	for(int i=g;i>=1;i--) cout<<a[i];
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
}                                                                                                