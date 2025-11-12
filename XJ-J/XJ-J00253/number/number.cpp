#include <bits/stdc++.h>
using namespace std;
string s,a;
int num=0;
int main()
{
    freopen("number.in","r","stdin");
    freopen("number.out","w","stdout");
    cin>>s;
    if(s.length()==1)
    {
    	cout<<s;
    	return 0;
	}
	for(int i=0;i<s.length();i++)
    {
    	if((s[i]>='0') && (s[i]<='9'))
    	{
    		num++;
    		a+=s[i];
        }
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(a[j]<a[i])
			{
				char t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<=num;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
