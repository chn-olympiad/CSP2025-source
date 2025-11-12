#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() 
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	
	cin>>s;
	getchar;
	for(int i=1;i<=s.size();i++)
	{
		if('1'<=s.size()<='0')
		{
			a[i]=s.size();
		}
	}
	for(int i=1;i<=s.size();i++)
	{
		cout<<a[i];
	}
	return 0;
}
