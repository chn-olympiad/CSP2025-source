#include<iostream>
using namespace std;

	int a[1005],b[1005];

int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	int jl;
	int xb=1;
	for(int i=1;i<=n;i++)
	{
		jl=a[i]+a[i+1];
		for(int j=i+2;j<=n;j++)
		{
			jl+=a[j];
			if(jl>a[j]*2) sum++;
			b[xb]=jl;
			xb++;
			jl-=a[j];
		}

	}
	for(int i=1;i<=n;i++)
	{
		jl=a[i]+a[i+1];
		int pd=0;
		for(int j=i+2;j<=n;j++)
		{

			jl+=a[j];
			for(int x=1;x<xb;x++)
			{
				if(b[xb]==jl) pd=1;
			}
			if(pd==0&&jl>a[j]*2)
			{
				sum++;
			}
		}
	}
	sum%=998;
	sum%=244;
	sum%=353;
	cout<<sum;
	return 0;
}