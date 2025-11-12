#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	int i,j,l,a[15]={0};
	cin>>s;
	l=s.size();
	for(i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
