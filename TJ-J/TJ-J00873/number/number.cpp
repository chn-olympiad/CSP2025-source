#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	len--;
	int j=1;
	for(int i=0;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=2;i--)
	{
		cout<<a[i];
	}
	return 0;
}
