#include <bits/stdc++.h> 
using namespace std;

string px(string s)
{
	int num=0;
	string s1;
	long long n;
	n = s.length();
	for(int i=0;i<=n;i++)
	{
		if('0'<=s[i] && s[i] <= '9')
		{	 
			s1+=s[i];		
		}
	}
	return s1;
}

char a[1000000];

int main()
{
	freopen("number2.in","r",stdin);
	//freopen("number1.out","w",stdout);
	string s,s1;
	char num='0';
	
	cin >> s;
	long long n,n1;
	n = s.length();
	s1=px(s);
	n1 = s1.length();
	
	for(int i=0;i<=n1;i++)
	{
		a[i]+=s1[i];
	}
	sort(a+1,a+n1+1);
	for(int i=0;i<=n1;i++)
	{
		cout<<s1[i];
	}		
	

	return 0;	
} 
