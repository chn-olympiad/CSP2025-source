#include<iostream>
using namespace std;
long long a[300];
int main()
{
	freopen("xor.in","r",stdin)
	freopen("xor.out","w",stdout)
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		if(k==0)
	{
		cout<<'1';
	}
	if(a[i]==k)
    {
  		sum++;
   	}
   	cout<<sum;
    }
	return 0; 
}
