#include <bits/stdc++.h>
using namespace std;
string s;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.length();i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			if(s[i]>=s[i+1])
			{
				swap(s[i],s[i+1]);
				a[i]+=s[i+1];
			}
		}
	}
	cout<<s;
}
