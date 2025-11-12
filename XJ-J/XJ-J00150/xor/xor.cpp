#include <bits/stdc++.h>;
using namespace std;
int n,m,a[100];
int main()
{
	freopen("xor.in","r",stdin);
	cin>>n>>m;
	a[1]=n-m;
	a[2]=n+m;
	a[3]=n/m;
	a[4]=n*m;
	a[5]=n%m;
	a[6]=n*n/m*m;
	a[7]=n/m/n%m;
	a[8]=(n+m)/m;
	a[9]=(n+m)/n;
	a[10]=2*n+3*m;
	int temp;
	for(int j=1;j<=10;j++)
	{
		for(int k=1;k<=9;k++)
		{
			if(a[k]<a[k+1])
			{
				temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	freopen("xor.out","w",stdout);
	cout<<a[0];
	return 0; 
}
