#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{
			a[i]=s[i];
			sum++;
		}
	}
	sort(a+1,a+1+sum);
	
	for(int i=0;i<sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
