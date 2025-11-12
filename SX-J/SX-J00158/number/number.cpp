#include<bits/stdc++.h>
using namespace std;
long long s[100001];
string a;
long long sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	bool b=true;
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]=='0')
		{
			s[sum]=0;
			sum++;
		}
		if(a[i]=='1')
		{
			s[sum]=1;
			sum++;
		}if(a[i]=='2')
		{
			s[sum]=2;
			sum++;
		}if(a[i]=='3')
		{
			s[sum]=3;
			sum++;
		}if(a[i]=='4')
		{
			s[sum]=4;
			sum++;
		}if(a[i]=='5')
		{
			s[sum]=5;
			sum++;
		}if(a[i]=='6')
		{
			s[sum]=6;
			sum++;
		}if(a[i]=='7')
		{
			s[sum]=7;
			sum++;
		}if(a[i]=='8')
		{
			s[sum]=8;
			sum++;
		}if(a[i]=='9')
		{
			s[sum]=9;
			sum++;
		}
	}
	sort(s,s+sum);
    	for(int i=sum-1;i>=0;i--)
    	cout<<s[i];
    return 0;
}