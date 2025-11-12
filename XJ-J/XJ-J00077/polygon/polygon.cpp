#include<bits/stdc++.h>
using namespace std;
int arr[5010];
int brr[5010];
int main()
{
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int m,sum=0;
	long long ans=0;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+m);
	for(int i=0;i<m;i++)
	{
		brr[i]=arr[i]+brr[i-1];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(brr[j]-brr[i]>2*arr[j])
			{
				ans++;
			}
		}
	}
	cout<<3*ans%998244353;
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
