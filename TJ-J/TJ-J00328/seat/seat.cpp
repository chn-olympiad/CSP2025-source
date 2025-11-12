#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=1,z;
	cin>>n>>m;
	int r,a[101],b[101];
	cin>>r;
	for(int i=1;i<n*m;i++) cin>>b[i];
	sort(b+1,b+n*m+1);
	long long s=n*m;
	for(int i=s-1,j=2;i>0;i--,j++) a[j]=b[i];
	for(int i=2,j=1;i<=s;i++,j++)
	{
		if(r>a[i])
		{
			if(j>n)
			{
				if(i%n==0)
				{
					q+=i/n-1;
				}
				else
				{
					q+=i/n;
				}
				if(i%n==1) z=i%n;
				else 
				{
					z=i%n;
					z=n-z;
				}
				break;
			}
			else
			{
				q=1;
				z=j;
				break;
			}
		}
	}
	cout<<q<<' '<<z;
	return 0;
}
