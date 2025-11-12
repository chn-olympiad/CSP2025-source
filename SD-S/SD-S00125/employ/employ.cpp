#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int c[502];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i-1]==0){
			cout<<0;
			return 0;
		}
		else
		{
			ans=ans*i;
		}
	}
	cout<<ans;
	return 0;
}

