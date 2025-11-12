#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ss[100001],sss=0,ssss=0;
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == '0')
		{
			
			ss[sss] = 0;
			sss++;
		}
		if(s[i] == '1')
		{
		
			ss[sss] = 1;
			sss++;
		}
		if(s[i] == '2')
		{
		
			ss[sss] = 2;
			sss++;
		}
		if(s[i] == '3')
		{
			
			ss[sss] = 3;
			sss++;
		}
		if(s[i] == '4')
		{
			
			ss[sss] = 4;
			sss++;
		}
		if(s[i] == '5')
		{
			
			ss[sss] = 5;
			sss++;
		}
		if(s[i] == '6')
		{
			
			ss[sss] = 6;
			sss++;
		}
		if(s[i] == '7')
		{
			
			ss[sss] = 7;
			sss++;
		}
		if(s[i] == '8')
		{
			
			ss[sss] = 8;
			sss++;
		}
		if(s[i] == '9')
		{
			ss[sss] = 9;
			sss++;
		}
	}
	for(int i=0;i<sss;i++)
	{
		if(ss[i] < ss[i+1])
		{
			ssss = ss[i];
			ss[i] = ss[i+1];
			ss[i+1] = ssss;
		}
	}
	for(int i=0;i<sss;i++)
	{
		cout << ss[i];
	}
}
