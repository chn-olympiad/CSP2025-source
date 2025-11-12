#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
string s;
int b[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') b[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	return 0;
}
