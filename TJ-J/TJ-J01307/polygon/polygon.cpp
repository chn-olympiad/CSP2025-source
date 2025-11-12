#include <bits/stdc++.h>
using namespace std;
int n,s;
int arr[5001];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		s+=arr[i];
	}
	
	sort(arr,arr+n);
	if(n<3)
		cout<<"0";
	else if(n==3&&s>arr[n-1]*2)
		cout<<"1";
	else if(n==3&&s<arr[n-1]*2)
		cout<<"0";
	
	return 0;
}

