#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int j=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	int ans=0;
	int sum=1;
	int o=j-1;
	while(o--)
	{
		sum*=10;
	}
	for(int k=j;k>=1;k--)
	{
		if(a[k]==0)
		{
			
		}
		else
		{
			ans+=sum*a[k];
			sum/=10;
		}
		
	}
	cout<<ans;
	return 0;
}
