#include<iostream>
#include<cstring>
using namespace std;
int m[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++) m[i]=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			m[s[i]-'0']++;
		}
	}
	long long n=0;
	for(int i=9;i>=0;i--)
	{
		if(m[i]!=0)
		{
			for(int j=1;j<=m[i];j++)
			{
				n=n*10+i;
			}
		}
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}