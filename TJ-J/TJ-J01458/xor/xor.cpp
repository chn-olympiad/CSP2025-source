#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a=0;
	long long b=0;
	cin>>a;cin>>b;
	int m=0;
	int arr[100000];
	for(int i=0;i<a;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<a;i++)
	{
		if(arr[i]==b)
		{
			m++;
		}
	}
	
	cout<<m;
	return 0;
}
