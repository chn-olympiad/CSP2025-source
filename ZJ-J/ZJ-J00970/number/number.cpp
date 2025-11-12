#include<bits/stdc++.h>
using namespace std;
#define int long long
int i,a[100100],t;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+t+1);
	for(i=t;i>=1;i--) cout<<a[i];
	return 0;
}

