#include<bits/stdc++.h>
using namespace std;
int n,k,ans,uuz;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				if(uuz==0)
				{
					uuz=1;
				}
				else{
					uuz=0;
					ans++;
				}
			}
			else 
			{
			ans++;
			uuz=0;
		}
		}
	}
	cout<<ans;
	return 0;
}
