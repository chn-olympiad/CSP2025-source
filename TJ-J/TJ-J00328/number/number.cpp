#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[100001];
	long long j=1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
