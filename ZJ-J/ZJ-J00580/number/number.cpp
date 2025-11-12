#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int b[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') b[s[i]-'0']++;
	for(int i=9;i>=0;--i){
		int t=b[i];
		while(t--) cout<<i; 
	}
}
//100 
