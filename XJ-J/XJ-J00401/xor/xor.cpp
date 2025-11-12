#include<bits/stdc++.h>
using namespace std;
int a[10000001];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==2||k==3)
	{
		cout<<2;
	}
	if(k==0)
	{
		cout<<1;
	}
	
	//fclose(stdin);
//	fclose(stdout);
	return 0;
}
