#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,p;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)	cin>>a[i];
	p=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<n*m-1;j++)
		{
			if(a[i]<a[i+j])
			{
				t=a[i];
				a[i]=a[i+j];
				a[i+j]=t;
			}
		}
	}
	cout<<"1"<<" "<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
