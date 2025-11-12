#include<bits/stdc++.h>
using namespace std;
const int N=5005; 
int a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	int max=-0x7fffffff;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			cout<<0;
		}sum+=a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
		
		if(sum>max*2)
		{
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}
