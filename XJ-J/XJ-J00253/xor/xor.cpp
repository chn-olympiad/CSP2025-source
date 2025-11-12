#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r","stdin");
    freopen("xor.out","w","stdout");
    int k,n,a[500005],num=0;
    cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
        if((a[i]^a[i+1])==k)
		{
			num++;
		}
		if((a[i] ^ a[i])==k)
		{
			num++;
		}
	}
	cout<<num;
	return 0;
} 
