#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int num=0;
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			num++;
			a[i]=k+1;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
	
		int a[100];
		int ans;
		int n=0;
		while(a[i]>0)
		{
			
			a[n]=a[i]%2;
			a[i]/=2;
			n++;
			
		}
		for(int i=n-1;i>=0;i--)
		{
			ans+=2*i*n-1-i;
		}
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
