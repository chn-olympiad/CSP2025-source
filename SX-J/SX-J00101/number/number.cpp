#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string a,b[1000010];
int c[1000010],q;

int main()
{
//	freopen("number.in","r".stdin);
//	freopen("number.out","w",stdout);
	cin>>a;
	int d=a;
	for(int i=1;i<=1000000;i++)
	{
		c[i]=1;
	}
	for(int i=1;i<=1000000;i=i*10)
	{
		b[q]=a[i]/i%10;
		q++;
	}
	for(int i=1;i<=1000000;i++)
	{
		cout<<b[i];
	}
	return 0;
}