#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=1e5+10,M=1e2+10,MOD=1e9+7;
string s;
ll a[10];
void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--) cout<<string(a[i],char(i+'0'));
}
int main(){
	IOS;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
