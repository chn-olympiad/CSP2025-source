#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],b[105];
void cmp()
{
	
	if(x>y) return ;
}
int main()
{	
	freopen("seat.in","r",strin);
    freopen("seat.out","w",strout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		sort(a+1,a+1+m*n,cmp());
		cout<<a[i]<<endl;
	}
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	if(n==1&&m<=10)
	{
		for(int i=1;i<=m;i++)
		{
			if(a[1]==a[i])
			{
				cout<<1<<" "<<i<<endl;
				return 0;
			}
		}	
	}
	return 0;
}
