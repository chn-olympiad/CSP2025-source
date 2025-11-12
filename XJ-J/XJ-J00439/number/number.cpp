#include<bits/stdc++.h>

using namespace std;

int a[1000015],t[11]={};
int main()
{
	freopen("number.in" , "r" , stdin); 
	freopen("number.out" , "w" , stdout); 
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		
		if(s[i]>='0' && s[i]<='9')
		{
			a[sum]=s[i]-'0';
			sum++;
			t[s[i]-'0']++;
		}
	}
	
	
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<t[i];j++)
		{
			if(t[i]!=0) 
				cout<<i;
		}
	}	
	return 0;	
} 
