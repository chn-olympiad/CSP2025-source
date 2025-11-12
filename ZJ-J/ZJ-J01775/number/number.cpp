#include<bits/stdc++.h>
using namespace std;
string s;
int n,num[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[++n]=s[i]-48;
	sort(num+1,num+n+1);
	for(int i=n;i>=1;i--)
		printf("%d",num[i]);
	return 0;
}