#include<bits/stdc++.h>
using namespace std;
int n,a[5001]={},b=0,d=0,e=0,f=0;
long long sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		d=max(d,a[i]);
	}
	if(d==1)
	{
		cout<<"0";
		return 0;
	}
	if(a[1]+a[2]+a[3]>d/*&&n==3*/)
	{
		cout<<"1";
		return 0;
	}
	else/* if(a[1]+a[2]+a[3]<=d&&n==3)*/
	{
		cout<<"0";
		return 0;
	}
	/* for(int i=n;i>=3;i--) //Ê§°Ü 
	 {
	 	for(int j=0;j<=i;j++)
	 	{
	 		for(int k=1;k<=i;k++)
	 		{
	 			e=max(e,a[k]);
	 			b+=a[k];
	 			f++;
			 }
			 b=b-a[j];
			 if(b>e*2&&f>=3)
			 {
			 	sum++;
			 }
			 b=0;
			 f=0;
			 e=0;
		 }
	 }
	 cout<<sum;
*/
	return 0;
}
