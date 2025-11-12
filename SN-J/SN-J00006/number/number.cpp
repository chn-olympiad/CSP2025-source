#include<bits/stdc++.h>

using namespace std;

long long n[100005];

int main()
{
	ifstream cin("1.in");
	ofstream cout("2.out");
	string s;
	int sum=0;
	int h;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			n[i]+=1;
			sum+=1;
		}
		if(s[i]=='2')
		{
			n[i]+=2;
			sum+=1;
		}
		if(s[i]=='3')
		{
			n[i]+=3;
			sum+=1;
		}
		if(s[i]=='4')
		{
			n[i]+=4;
			sum+=1;
		}
		if(s[i]=='5')
		{
			n[i]+=5;
			sum+=1;
		}
		if(s[i]=='6')
		{
			n[i]+=6;
			sum+=1;
		}
		if(s[i]=='7')
		{
			n[i]+=7;
			sum+=1;
		}
		if(s[i]=='8')
		{
			n[i]+=8;
			sum+=1;
		}
		if(s[i]=='9')
		{
			n[i]+=9;
			sum+=1;
		}
		if(s[i]=='0')
		{
			sum+=1;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		for(int i=0;i<s.size();i++)
		{
			if(n[i]<n[i+1])
			{
				h=n[i+1];
				n[i+1]=n[i];
				n[i]=h;
			}
		}		
	}
	for(int i=0;i<sum;i++)
	{
		cout<<n[i];
	}
	return 0;
}
