#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int i,t,a[1000010];
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-'0';
	sort(a+1,a+1+t);
	for(i=t;i>=1;i--)cout<<a[i];
}