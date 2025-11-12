#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(register int i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9')++cnt[s[i]-'0'];
	for(register int i=9;i>=0;--i)
		if(cnt[i])
		for(register int j=1;j<=cnt[i];++j)putchar(i+'0');
	return 0;
}
