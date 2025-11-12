#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char maxa;
	int k=0;
	cin>>s;
	for(int i=0;i<s.length()-1;i++)
	{
		
		if(s[i]<s[i+1])
		{
			maxa=s[i];
			s[i]=s[i+1];
			s[i+1]=maxa;
		}
	}
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cout<<s[i];
		}
		else
		{
			
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
