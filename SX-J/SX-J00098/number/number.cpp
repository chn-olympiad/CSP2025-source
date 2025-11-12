#include <bits/stdc++.h>
using namespace std;
string s;
long long b,a[1000006],j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(int i=0;i<=b;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			j++;
			a[j]=s[i]-48;
		}
	}
	b=0;
	sort(a+1,a+1+j);
	reverse(a+1,a+1+j);
	for(int i=1;i<=j;i++)
	{
		b=b*10;
		b+=a[i];
	}
	cout<<b;
	return 0;
}