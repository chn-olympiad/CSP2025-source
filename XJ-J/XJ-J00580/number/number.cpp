#include <bits/stdc++.h>
using namespace std;
int a[1000005],t;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++t]=s[i]-'0';
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
		cout<<a[i];
	return 0;
}
