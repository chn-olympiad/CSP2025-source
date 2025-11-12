#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	if(s[i]>='0'&&s[i]<='9')
	a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++)
	cout<<a[i];
	return 0;
}
