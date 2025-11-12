#include <iostream>
using namespace std;
long long t,n,k,i,j,a[100005][4],z,b[100005],cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cnt=0;
		cin>>n;
		for(j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			b[j]=a[j][1];
		}
		for(j=1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(b[k]>b[j])
				{
					z=b[j];
					b[j]=b[k];
					b[k]=z;
				}
			}
		} 
		for(j=1;j<=n/2;j++)
		{
			cnt=cnt+b[j];
		} 
		cout<<cnt<<endl;
	}
	return 0;
}
