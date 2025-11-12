#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int xiabiao,sum;
	string s,a,daan;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]<='1'||s[i]<='9')
		{
			a+=s[i];
		}
	}
	for(int i=0;i<a.size();i++)
	{
		sum=47;
		for(int j=0;j<a.size();j++)
		{
			if(a[j]>(char)sum)
			{
				sum=(int)a[j];
				daan[i]=a[j];
				xiabiao=j;
			}
		}
		a[xiabiao]=' ';
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<daan[i];
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
