#include<bits/stdc++.h>
using namespace std;
int main(){	
	char a[1000005];
	int l=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[l-1]=s[i];
			l++;
		}
	}
	for(int i=0;i<l;i++)
	{
		if(a[i]>a[i-1])
		{
			swap(a[i],a[i-1]);
		}
	}
	for(int i=0;i<l;i++)
	{
		cout<<a[i-1];
	}
	
	return 0;
} 
