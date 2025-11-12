#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,h=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		h+=arr[i];
	}
	sort(arr,arr+n);
	if(n==3&&h>2*arr[n-1]) cout<<3;
	return 0;
}
