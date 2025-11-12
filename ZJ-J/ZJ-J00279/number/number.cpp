#include<bits/stdc++.h>
using namespace std;
string a;
long long n[1000005],l1 = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long l = a.size();
	for(int i = 0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			l1++;
			n[l1] = a[i]-'0';
		}
	}
	sort(n+1,n+1+l1);
	for(int i = l1;i>=1;i--)
	{
		cout<<n[i];
	}
	return 0;
}