#include<bits/stdc++.h>
using namespace std;
long long n,num=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
			{
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]+a[j]+a[j+1]>a[i]*2||a[i]+a[i+1]+a[j]>a[i]*2)
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
