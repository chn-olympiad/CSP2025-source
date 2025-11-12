#include<bits/stdc++.h>
using namespace std;
long long n,k,num=0;
int a[255];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]+a[j]==k || a[i]-a[j]==k || a[j]-a[i]==k)
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
