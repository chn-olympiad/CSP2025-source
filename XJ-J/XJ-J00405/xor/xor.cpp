#include<iostream>
using namespace std;
int a[500555];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			s++;
		}
	}
	if(k==0)
	{
		cout<<s;
	}
	return 0;
}
