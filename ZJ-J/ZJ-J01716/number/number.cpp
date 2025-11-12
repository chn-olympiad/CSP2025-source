#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[1000100],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}//100pts 已检查