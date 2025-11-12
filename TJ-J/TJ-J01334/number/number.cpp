#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	string s;
	for(int i=0;i<=sizeof(s);i++)
	{
		cin>>s[i];
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			v[i]=(int)(s[i]-48);
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<sizeof(v);i++)
	{
		cout<<v[i];
	}
	return 0;
}
