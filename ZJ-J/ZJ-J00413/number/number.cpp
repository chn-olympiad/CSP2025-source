#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1001000],k;
main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		a[++k]=s[i]-'0';
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)
	cout<<a[i];
}
