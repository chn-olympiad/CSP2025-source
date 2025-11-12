#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int f=0;
			for(int k=i;k<=j;k++) f=a[k]|f;
			if(f==k)
			{
				sum++;
				i=j;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}