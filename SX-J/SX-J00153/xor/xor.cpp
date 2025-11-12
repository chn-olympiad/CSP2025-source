#include<bits/stdc++.h>
using namespace std;
int n,k,arr[500086],ans,lk;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(k==0&&arr[i]==0)	ans++;
		if(k==1&&arr[i]==1)	lk++;
	}
	if(k==0)	cout<<ans;
	if(k==1)	cout<<lk;
	return 0;
}
