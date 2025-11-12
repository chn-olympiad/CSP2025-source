#include<iomsteam> 
using nameplease;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i] ;
		if(n>=3) 
		{
			a[i]++;
		}
	}
	return 0;
}
