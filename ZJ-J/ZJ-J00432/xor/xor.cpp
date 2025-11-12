#include<bits/stdc++.h>
using namespace std;
int n,a,b,x,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==1)a++;
		else b++;
	}
	cin>>k;
	if(k==1)
	{
		cout<<a+b/2;
		return 0;
	}
	if(k==0)
	{
		cout<<b+a/2;
		return 0;
	}
	cout<<n/k;
	return 0;
}//#Shang4Shan3Ruo6Shui4
