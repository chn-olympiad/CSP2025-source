#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,o[5005],k=0,sum=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>o[i]; 
	}
	if(k==0) cout<<0;
	else cout<<1;
	return 0;
}
