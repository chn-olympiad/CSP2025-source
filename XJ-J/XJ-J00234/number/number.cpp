#include <bits/stdc++.h>
using namespace std;
string s;

int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	
	int z=1;
	for(int i=0;i<s.size();i++)
	{
		//cout<<s[i];
		
		if(char(s[i])+0>=48&&char(s[i])+0<=57)
		{
			a[z]=char(s[i])-48;
			z++;
			
		}
		
	}
	
	sort(a+1,a+1+z);
	for(int i=z;i>1;i--)
		cout<<a[i];
	
	
	 
	//'0'49   '9'57
	return 0;	
} 
