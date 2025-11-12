#include<cstdio>
#include<iostream>
using namespace std;
int n=0,k=0,flag=0,sum=0,a[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		if(b[i]==k||a[i]==k){
			sum++;
			b[i]=0;
		}
	}
	cout<<sum;
	return 0;
}
