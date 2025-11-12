#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9')
			a[++a[0]]=int(s[i]-'0');
	sort(a+1,a+1+a[0]);
	for(int i=a[0];i;--i)
		printf("%d",a[i]);
		return 0;
}
