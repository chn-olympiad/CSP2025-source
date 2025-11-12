#include<bits/stdc++.h>
using namespace std;
bool sid(long long n,long long m)
{
	return m<n;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100001];
	cin>>a;
	long long b[100001]={0};
	long long sum=0;
	for(long long i=0;i<strlen(a);i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[sum]=a[i]-'0';
			sum++;
		}
	}
	sort(b,b+sum,sid);
	for(long long i=0;i<sum;i++)
	{
		cout<<b[i];
	}
	return 0;
}
