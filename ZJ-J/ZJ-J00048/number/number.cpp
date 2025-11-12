#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int len,cnt;
	cin>>s;
	len=s.size();
	cnt=0;
	for(int i=0;i<len;i++)
		if(48<=s[i]&&s[i]<=57)
			a[++cnt]=s[i]-48;
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
	return 0;
}
