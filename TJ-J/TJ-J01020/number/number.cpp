#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans,len=s.length();
	int maxs=0;
	int maxd=0;
	int cnt=0;
	int a[s.length()];
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	int b[cnt+5];
	memset(b,0,sizeof(b));
	for(int i=0;i<cnt;i++)
	{
		maxs=0;
		maxd=0;
		for(int j=0;j<cnt;j++)
		{
			if(maxs<=a[j]&&b[j]==0)
			{
				maxs=a[j];
				maxd=j;
			}
		}
		b[maxd]=1;
		ans=ans*10+maxs;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
}
