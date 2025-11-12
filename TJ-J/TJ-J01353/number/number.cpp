#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int li[s.length()],cnt=0,ans=0,yin=1;
	for(int i=0;i<s.length();i++)
	{
		li[i]=0;
		if(s[i]>=48&&s[i]<=57)
		{
			li[cnt]=s[i]-'0';
			cnt+=1;
			yin*=10;
		}
	}
	for(int i=0;i<=cnt;i++)
	{
		for(int j=0;j<=cnt;j++)
		{
			if(i!=j)
			{
				if(li[i]>li[j]&&i<j)
				{
					li[j]+=li[i];
					li[i]=li[j]-li[i];
					li[j]-=li[i];
				}
			}
		}
	}
	for(int i=cnt;i>=0;i--)
	{
		if(li[i]==0)
		{
			li[i]*=yin;
		}
		else
		{
			li[i]=li[i]*yin;
		}
		yin/=10;
		ans+=li[i];
	}
	cout<<ans/10;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
