#include <iostream>
using namespace std;
int n=1;
string a,b[1000005],c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	c=a;
	for (int i=0;i<=a.length();i++)
	{
		if (a[i]>='0' and a[i]<='9')
		{
			b[n]=a[i];
			n++;
		}
	}
	for (int i=1;i<=a.length();i++)
	{
		for (int j=1;j<=i;j++)
		{
			if (b[i]>b[j])
			{
				swap(b[i],b[j]);
			}
		}
	}
	for (int i=1;i<n;i++)
	{
		cout<<b[i];
		
	}
    
    
    
	return 0;
} 
