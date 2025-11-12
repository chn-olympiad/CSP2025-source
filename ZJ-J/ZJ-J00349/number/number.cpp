#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int t,ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if('0'<=s[i]&&s[i]<='9'){
			t++;ans[t]=s[i]-48;
		}
	}
	sort(ans+1,ans+t+1);
	for(int i=t;i>=1;i--)cout<<ans[i];
	return 0;
}
