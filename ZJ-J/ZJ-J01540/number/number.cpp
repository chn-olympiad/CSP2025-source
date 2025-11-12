#include<bits/stdc++.h>
using namespace std;
string s;
int slen;
int a[1000005];
long long cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	slen=s.size();
	for(int i=0;i<slen;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
		printf("%d",a[i]);
	return 0;
}
