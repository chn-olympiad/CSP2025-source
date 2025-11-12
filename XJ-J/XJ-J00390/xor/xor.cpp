#include<bits/stdc++.h>
using namespace std;
int xorsum(int a,int b,vector<int>& m)
{
	int sum=0;
	for(int i=a;i<=b;i++)
	{
		sum=sum xor m[i];
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,Max=0;
	cin>>n>>k;
	vector<int> m(n);
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long count=0;
		for(int j=0;j+i<n;j+=i)
		{
			if(xorsum(j,j+i,m)==k) count++;
		}
		Max=max(Max,count);
	}
	cout<<Max;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
 
