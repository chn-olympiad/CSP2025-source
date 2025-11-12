#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],summ;
bool boo[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==m)
		{
			boo[i]=1;
			summ++;
		}
	}
	bool yes=0;
	for(long long i=2;i<=n;i++)
	{
		yes=1;
		for(long long ii=1;ii<=n;ii++)
		{
			bool ool=0;
			int ans;
			if(boo[ii]!=1)
			{
				ans=a[ii];
				ool=0;
				for(int j=1;j<i;j++)
				{
					if(boo[j+ii]==1)
					{
						ool=1;
						break;
					}
					ans^=a[j+ii];
				}
				if(ans==m && ool==0)
				{
					summ++;
					for(int j=1;j<i;j++)
					{
						boo[ii+j]=1;
					}
					boo[ii]=1;
				}
				if(ool==0)yes=0;
			}
		}
		if(yes)break;
	}
	cout<<summ<<endl;
	return 0;
}

