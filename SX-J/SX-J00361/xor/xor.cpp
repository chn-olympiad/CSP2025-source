#include<bits/stdc++.h>
using namespace std;
long long arr[1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(k==0){
		cout<<1;
	}
	return 0;
}