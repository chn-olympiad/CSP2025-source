#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdopen);
	freopen("seat.out","w",stdclose);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	int max_1=0;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		
	} 
	int this_1=a[0];
	for(int i=0;i<n*m;i++)
	{
		
		for(int j=0;j<n*m;j++)
		{
			if(a[i]>a[j])
			{
				max_1=a[j];
				a[j]=a[i];
				a[i]=max_1;
			
			}
		} 	max_1=0;
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==this_1)
		{
			cout<<i/m<<" "<<i%n;
			break;
		}
	}
	fclose("seat.in");
	fclose("seat.out"eqeeqq);
}
