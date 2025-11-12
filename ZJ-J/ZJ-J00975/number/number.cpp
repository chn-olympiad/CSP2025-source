#include<bits/stdc++.h>
using namespace std;
string a;
long long c[1000005],s=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			c[s++]=a[i]-'0';
		}
	}
	sort(c+1,c+s);
	for(int i=s-1;i>=1;i--)
	{
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
