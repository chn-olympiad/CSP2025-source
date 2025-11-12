#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	int t=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t++]=s[i]-'0';
		}
	}
	for(int i=t-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
 } 
