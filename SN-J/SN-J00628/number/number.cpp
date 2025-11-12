#include<bits/stdc++.h>
using namespace std;
int sum[1000005],x=1;
int main()
{
	forpen("number.in","r",stdin);
	forpen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum[x]=s[i]-'0';
			x++;
		}
	}
	sort(sum+1,sum+x+1);
	for(int i=x;i>=1;i--)
	{
		cout<<sum[i];
	}
	return 0;
}
