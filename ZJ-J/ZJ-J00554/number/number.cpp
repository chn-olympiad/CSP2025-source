//»áÓ®Âð£¿ 
#include<bits/stdc++.h>
using namespace std;
int n,ton[10];
string s;
void solve(){
	cin>>s;
	n=s.size(),s=' '+s;
	for(int i=1;i<=n;i++) if(s[i]>='0'&&s[i]<='9') ton[s[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=ton[i];j++) cout<<i;
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
