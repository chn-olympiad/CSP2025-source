#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
int t,bj[mx];
string s;
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>s;
	int len=s.size();
	s=" "+s;
	for(int i=1;i<=len;i++) bj[s[i]]++;
	for(int i='9';i>='0';i--) for(int j=bj[i];j>=1;j--) cout<<i-'0';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=1;
	colse();
	while(t--) solve();
	return 0;
}