#include<bits/stdc++.h>
#include<fstream>
std::ifstream cin("number.in");
std::ofstream cout("number.out");
int main()	
{
	char s[1000005];
    int len=0;
    int ans;
	for(int i=0;i<1000005;i++)
	{
		cin>>s[i];
		len++;
	}
	int n[1000005];
	
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n[i]=s[i];
			ans++;
		}
	
	    for(int i=0;i<len;i++)
	    {
			if(n[i]>n[i+1])
			{
				int sum;
				sum=n[i];
				n[i]=n[1+1];
				n[i+1]=n[i];
			}
		}
	}
	for(int i=0;i<1000005;i++)
	{
		cout<<n[i];
	}
	return 0;
}
