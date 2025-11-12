#include<iostream>
using namespace std;
long long b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=0,t;
	for(int i=0;i<a.size() ;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i]-'0';
			j++;
		}
	}
	int s=j;
	for(int i=0;i<j;i++)
	{
		for(int k=0;k<s;k++)
		{
			if(b[k]<b[k+1])
			{
				t=b[k];
				b[k]=b[k+1];
				b[k+1]=t;	
			}
		}
		s--;
	}
	for(int i=0;i<j;i++)
	{
		cout<<b[i];
	}
	return 0;
}
