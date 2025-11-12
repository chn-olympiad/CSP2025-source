#include<iostream>
using namespace std;
int main()
{
	string s;
	int n[10005]={0},i,t=1,m=0;
	cin>>s;
	for(i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='0')
		{
			n[t]=0;
			t++;
		}
		else if(s[i]=='1')
		{
			n[t]=1;
			t++;
		}
		else if(s[i]=='2')
		{
			n[t]=2;
			t++;
		}
		else if(s[i]=='3')
		{
			n[t]=3;
			t++;
		}
		else if(s[i]=='4')
		{
			n[t]=4;
			t++;
		}
		else if(s[i]=='5')
		{
			n[t]=5;
			t++;
		}
		else if(s[i]=='6')
		{
			n[t]=6;
			t++;
		}
		else if(s[i]=='7')
		{
			n[t]=7;
			t++;
		}
		else if(s[i]=='8')
		{
			n[t]=8;
			t++;
		}
		else if(s[i]=='9')
		{
			n[t]=9;
			t++;
		}
	}
	for(i=1;i<t;i++)
	{
		for(int j=1;j<=t-i;j++)
		{
			if(n[j]<n[j+1])
			{
				m=n[j];n[j]=n[j+1];n[j+1]=m;
			}
		}
	}
	for(i=1;i<t;i++)
	{
		cout<<n[i];
	}
	return 0;
}
