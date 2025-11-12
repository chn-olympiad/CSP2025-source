#include <bits/stdc++.h>
using namespace std;
int n,arr[5005],arr1[5005],ans=0,sum,maxn;
void f(int x,int k)
{
	if(x==n)
	{
		sum=0,maxn=-1;
		for(int i=0;i<x;i++)
		{
			cout<<arr[i]<<' ';
			maxn=max(arr[i],maxn);
			sum+=arr[i];
		}
		cout<<endl;
		return;
	}
	else
	{
		for(int i=k;i<x;i++)
		{
			arr[x]=arr1[k];
			f(x+1,k+1);
		}
	}
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	for(int i=1;i<=n;i++)
	{
		f(i,0);
		if(sum>maxn*2)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
