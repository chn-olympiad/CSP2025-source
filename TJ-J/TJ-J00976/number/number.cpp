#include<bits/stdc++.h>
using namespace std;
strong s;
long  sum ;
sum = 0;
int main() {
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i = 0,i <= s,i++)
	{
			if(s[i]=9)
			{
				sum += s[i];
				
			}
		
    }
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=8)
			{
				sum*10+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=7)
			{
				sum*100+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=6)
			{
				sum*1000+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=5)
			{
				sum*10000+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=4)
			{
				sum*100000+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=3)
			{
				sum*1000000+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=2)
			{
				sum*10000000+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=1)
			{
				sum*100000000+s[i]=sum;
			}
		
	}
	for(int i = 0,i <= s,i++)
	{
			if(s[i]=0)
			{
				sum*1000000000+s[i]=sum;
			}
		
	}
	cout << sum;
    return 0;
}
