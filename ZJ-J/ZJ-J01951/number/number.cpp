//AC 100pts
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,ans;
void solve(){
	cin>>s;
	for(auto i:s)
		if(isdigit(i))
			ans+=i;
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	while(ans.size()>1&&ans[0]=='0') ans.erase(0,1);
	cout<<ans<<'\n';
	return;
}
int main(){
//system("fc number.out number.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
