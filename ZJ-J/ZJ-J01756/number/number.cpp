#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+10;
string s;
ll ans[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	ll cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0') ans[++cnt]=s[i]-'0';
	}
	sort(ans+1,ans+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}