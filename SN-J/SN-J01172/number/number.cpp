#include<bits/stdc++.h>
using namespace std;
string s;
string y;
int cnt=0,cnt1=0,cnt2=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]-'A'<0)
		{
			y[++cnt]=s[i];
			cnt1++;
		}
	}

	for(int i=1;i<cnt1+1;i++)
	{
		for(int j=i+1;j<cnt1+1;j++)
		{
			if(y[i]<y[j])
			{
				char t=y[j];
				y[j]=y[i];
				y[i]=t;
			}
		}
	}
	for(int i=1;i<cnt1+1;i++)
	{
		cout<<y[i];
	}
	
	return 0;
} 
