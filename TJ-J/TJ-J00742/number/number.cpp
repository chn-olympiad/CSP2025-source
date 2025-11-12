#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,x;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			cout<<s[i];
		}
	}
	return 0;
} 
