#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string s1="";
	cin>>s;
	long long len=0;long long son=0;
	long long q=0;
	while(s[q]!='\0')
	{
		if(s[q]>='0'&&s[q]<='9')
		{
			s1+=s[q];
			len++;	
		}
		q++;
	}
	for(long long i=len;i>1;i--)
	{
		for(long long j=1;j<i;j++)
		{
			if(s1[j]>s1[j-1])
			{
				char t=s1[j-1];
				s1[j-1]=s1[j];
				s1[j]=t;
			}
		}
	}
	for(long long i=0;i<len;i++)
	{
		son*=10;
		son=son+(s1[i]-'0');
	}
	cout<<son;
	return 0;
}
