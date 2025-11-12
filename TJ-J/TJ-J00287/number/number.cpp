#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int num1=s.size(),num2=0;
	for(int i=0;i<num1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[num2]=s[i]-'0';
			num2++;
		}
	}
	sort(a,a+num2);
	for(int i=num2-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
//0:48 9:57
