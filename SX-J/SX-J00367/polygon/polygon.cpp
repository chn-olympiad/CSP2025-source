#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int d=a[n]*2;
	for(int j=3;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			int s=0;
			for(int k=i;k<=i+j;k++) s+=a[k];
			if(s>d) sum++;
		}
	}
	cout<<sum%998244353;
	return 0;
}