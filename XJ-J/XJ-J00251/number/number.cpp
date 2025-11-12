#include<bits/stdc++.h>
using namespace std;
string st1;
int num[50];


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st1;
	int len=st1.size(),t=0,i;
	for(i=0;i<len;i++)
	{
		if('0'<=st1[i]&&st1[i]<='9')
		{
			for(int j=0;j<=9;j++)
			{
				if(st1[i]-'0'==j)
				{
					num[j]++;
				}
			}
		}
	}
	for(i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			cout<<i;
		}		
	}
	return 0;
 } 
