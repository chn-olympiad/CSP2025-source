#include<iostream>
using namespace std;
	
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int sum=0;
	int q, n;
	cin >> q >> n;
	int a[100];
	int b[100];
	for(int i=0;i<100;i++)
	{
		cin >>a[i] >> b[i];
	}
	for(int i=0;i<100;i++)
	{
		if(a[i]=b[i])
		{
			sum=0;
		}
	}
	cout << sum;
		
	return 0;
} 
	
