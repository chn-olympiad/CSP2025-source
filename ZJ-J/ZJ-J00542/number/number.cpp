#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int a[M],sss;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[++sss]=s[i]-'0';
	sort(a+1,a+1+sss);
	for(int i=sss;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}
