#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	bool b=0;
	cin>>s;
	long long a[s.length()+5]={0},num=0,max_m,ans=0,k=0;
	if(s.length()>=1&&s.length()<=1000000)
	{
		for(int i=0;i<=s.length();i++) if(s[i]>48&&s[i]<=57||s[i]<=122&&s[i]>=97) b=1;
		if(b)
		{
			for(int i=0;i<=s.length();i++)
			{
				if(s[i]>=48&&s[i]<=57)
				{
					a[k]=s[i]-'0';
					num++;
					k++;
				}
			}
			for(int i=0;i<num;i++)
			{
				max_m=0;
				for(int j=0;j<=num;j++) max_m=max(max_m,a[j]);
				ans=ans*10+max_m;
				for(int j=0;j<=num;j++)
				{
					if(a[j]==max_m)
					{
						a[j]=0;
						break;
					}
				}
			}
			if(ans>=0) cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
