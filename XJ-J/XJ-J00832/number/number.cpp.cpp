#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num=0,sum=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<='1'&&s[i]>='9')
		{
			num+=s[i];
		}
	}
	cout<<num; 
	return 0;
}
