#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,a[100000],t;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t,greater<long long int>());
	for(j=1;j<=t;j++)
	{
		cout<<a[j];
	}
	return 0;
} 
