#include<bits/stdc++.h>
using namespace std;
#define int long long
string str;
int s[1000005],cnt=0;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9')
			s[++cnt]=str[i]-'0';
	sort(s+1,s+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%lld",s[i]);
	return 0;
}

