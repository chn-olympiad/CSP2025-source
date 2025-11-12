#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		if(x==k)
		{
			sum++;
			continue;
		}
		int j=i+1;
		while(1)
		{
			x=(x^a[j]);
			if(x==k)
			{
				sum++;
				break;
			}
			j++;
			if(j>n) break;
		}
		i=j;
	}
	cout<<sum;
	return 0;
}