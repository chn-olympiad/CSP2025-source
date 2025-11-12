#include <iostream>
#include <stdio.h>
using namespace std;
int a[105];	
int cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c,r;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//cout<<n<<m<<endl;
	if(n==1&&m!=1)
	{
		for(int i=1;i<=m;i++)
		{
			if(a[1]>a[i+1])
			cnt++;
			else
			continue;
		}
		cout<<"1"<<' '<<cnt;
	}	
	if(n==1&&m==1)
	{
		cout<<"1 1";
	}
}
