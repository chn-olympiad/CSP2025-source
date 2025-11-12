#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			ans++;
	}
	if(n==3)
	{
		if(a[0]*2>=a[0]+a[1]+a[2]||a[1]*2>=a[0]+a[1]+a[2]||a[2]*2>=a[0]+a[1]+a[2])
			cout<<0;
		else
			cout<<1;
		return 0;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}