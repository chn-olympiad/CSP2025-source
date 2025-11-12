#include<bits/stdc++.h>
using namespace std;
int a[1000010],l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]>='0' && s[i]<='9')
	a[l++]=s[i]-'0';
	sort(a,a+l,greater<int>());
	for(int i=0;i<l;i++)cout<<a[i];
	return 0;
}
