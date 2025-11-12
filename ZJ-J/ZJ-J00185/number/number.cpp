#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++sum]=s[i]-'0';
		}
	}
	sort(num+1,num+sum+1);
	for(int i=sum;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}