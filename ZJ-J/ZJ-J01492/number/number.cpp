#include<bits/stdc++.h>
using namespace std;
#define ll int
string s;
ll ans[1000005],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')ans[++n]=s[i]-'0';
	}
	sort(ans+1,ans+1+n);
	reverse(ans+1,ans+1+n);
	for(ll i=1;i<=n;i++)cout<<ans[i];
	return 0;
}
