#include<bits/stdc++.h>
using namespace std;
long long n,k; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	else cout<<n/255;
	return 0;
}

