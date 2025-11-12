#include<bits/stdc++.h>
using namespace std;
string s,a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.length();i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			a[i]=s[i];
			cout<<max(a[i],a[i+1]);
		}
	}
	return 0;
}
