#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1100000],cnt=0,ans=0;	
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[cnt]=s[i]-48;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	long long num=1;
	for(int i=0;i<cnt;i++)
	{
		num*=10;
	}
	for(int i=0;i<cnt;i++)
	{
		ans+=a[i]*num;
		num/=10;
	}
	cout<<ans<<endl;
	return 0;
}
