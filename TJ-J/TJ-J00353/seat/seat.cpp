#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,max_m,num,c,r;
	cin>>n>>m;
	long long a[(n*m)+5],b[(n*m)+5];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int q=a[1];
	for(int i=1;i<=n*m;i++)
	{
		max_m=0;
		for(int j=1;j<=n*m;j++) max_m=max(max_m,a[j]);
		b[i]=max_m;
		for(int j=0;j<=num;j++)
		{
			if(a[j]==max_m)
			{
				a[j]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n*m;i++) if(b[i]==q) num=i;
	if(num%n) c=num/n+1;
	else c=num/n;
	if(c%2) r=n-(num-1)%n;
	else r=(num-1)%n+1;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
