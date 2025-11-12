#include<iostream>
using namespace std;
long long i,j,t,s=0,len,b[1000000];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	for(i=0;i<=len-1;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			s=s+1;
			b[s]=a[i]-48;
		}	
	}
	for(i=1;i<=s;i++)
	{
		for(j=i+1;j<=s;j++)
		{
			if(b[j]>b[i])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(i=1;i<=s;i++)
	{
		cout<<b[i];
	}
	return 0;
}
