#include<bits/stdc++.h>
using namespace std;
bool sid(long long z1,long long z2)
{
	return z1>z2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	long long a[10001]={0};
	cin>>n>>m;
	for(long long i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	long long su=n*m;
	long long r=a[0];
	long long weizhi=0;
	sort(a,a+su,sid);
	for(long long i=0;i<su;i++)
	{
		if(a[i]==r)
		{
			weizhi=i+1;
		}
		
	}
	long long zhen=weizhi/n;
	long long yu=weizhi%n;
	if(yu==0)
	{
		if((zhen+1)/2!=0)
		{
			cout<<zhen<<' '<<n<<endl;
		}
		else
		{
			cout<<zhen<<' '<<'1'<<endl;
		}
	}
	else
	{
		if((zhen+1)%2!=0)
		{
			cout<<zhen+1<<' '<<yu<<endl;
		}
		else
		{
			cout<<zhen+1<<' '<<(n+1)-yu<<endl;	
		}
	}
	return 0;
 } 
