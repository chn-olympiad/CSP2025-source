#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
char ans[1000005];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s;
	for(int i = 0;i<s.size();i++)
		if(isdigit(s[i])) ans[++cnt]=s[i];
	sort(ans+1,ans+cnt+1);
	for(int i = cnt;i;i--) cout<<ans[i];
	return 0;
}
