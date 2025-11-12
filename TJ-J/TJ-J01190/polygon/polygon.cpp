#include <iostream>
using namespace std;
int n,sum=0,a[5005];
int main()
{
	freopen("polygon.in","r",strin);
    freopen("polygon.out","w",strout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]+a[i-1]>a[i+1]&&a[i-1]+a[i+1]>a[i]&&a[i]+a[i+1]>a[i-1])
		{
			sum++;
			cout<<a[i-1]<<" "<<a[i]<<" "<<a[i+1]<<endl;
		}
		
	}
	cout<<sum;
	return 0;
}
