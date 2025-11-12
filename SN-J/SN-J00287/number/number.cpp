//岳颢晨 SN-J00287 西安滨河学校 
#include<bits/stdc++.h>
int b[1000000];
bool f(int a,int b)
{
	if(a>b)
	{
		return 1;
	}
	return 0;
}
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int sum=0;
	cin>>a;
	int t=a.size();
	for(int i=0;i<t;i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			b[i]=a[i]-48;
			sum++;
		}
	}
	sort(b,b+t,f);
	for(int i=0;i<sum;i++)
	{
		cout<<b[i];
	}
	return 0;
}
