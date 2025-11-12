#include <bits/stdc++.h>
using namespace std;
long long chengfang(int);
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	short number[1000000];
	int b=0;
	long long result=0;
	cin>>a;
	for (int i=0;i<a.length();i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			number[b]=a[i]-48;
			b+=1;
		}
	}
	sort(number,number+b);
	for (int i=b;i>=0;i--)
	{
		result+=number[i]*chengfang(i);
	}
	cout<<result;
	return 0;
}

long long chengfang(int x)
{
	int cnt=1;
	for (int i=0;i<x;i++)
	{
		cnt*=10;
	}
	return cnt;
}
