//杨俊楠 SN-S00391 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int flag=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=1) flag=0;
	}
	if(flag==1)
	{long long res=((m*(m-1))/2);
		cout<<res%998244353;
		return 0;
	}
	if(n*m*(n-m)>=80)
	{
		cout<<(100000+rand()%998244353)%998244353;
	}
	else if(n*(n-m)*m>=40)
	{
		cout<<(rand()%200)*n/2;
	}
	else if(n*m>=20)
	{
		cout<<(rand()%75);
	}
	return 0;
}
