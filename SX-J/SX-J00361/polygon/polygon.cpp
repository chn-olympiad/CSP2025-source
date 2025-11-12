#include<bits/stdc++.h>
using namespace std;
int arr[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;//数量
	long long max=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		max=max+arr[i];
	}
	long long y=0;
	if(arr[n]*2<max){
		y++;
	}
	cout<<y;
	return 0;
}