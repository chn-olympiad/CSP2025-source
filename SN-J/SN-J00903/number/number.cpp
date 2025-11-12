#include<bits/stdc++.h>
using namespace std;
int main()
{
	forpen("number.in","r","stdin");
	forpen("number.out","w","stdout");
	string s;
	cin>>s;
	string r;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{
			cout<<s[i];
		}
}
	return 0;
}
