#include<bits/stdc++.h>
using namespace std;
long long ma=LLONG_MIN;
string s,t="",s1="",s2="";
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		ma=LLONG_MIN;
		s1="";
		for(int j=0;j<=s.size()-1;j++)
		{
			if(s[j]>='0'&&s[j]<='9')
			{
				if(ma<(s[j]-'0')&&s2[j]!='.')
				{
					ma=s[j]-'0';
				}
		    }
		}
		for(int j=0;j<=s.size()-1;j++)
		{
			if(s[j]>='0'&&s[j]<='9')
			{
				if(s[j]-'0'==ma)
				{
					s2[j]='.';
					s1=s1+s[j];
				}
		    }
		}
		t=t+s1;
	}
	cout<<t;
	return 0;
}