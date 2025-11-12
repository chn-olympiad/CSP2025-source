#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++) cin >>a[i];
	int ans=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		if(a[i]==ans)
		{
			if(i%n==0)
			{
				int ans=i/n;
				if(ans%2==1)
				{
					if(i%n==0) cout <<ans<<" "<<n;
					else cout <<ans<<" "<<i%n;
				}
				else
				{
					if(i%n==0) cout <<ans<<" "<<n;
					else cout <<ans<<" "<<n-(i%n)+1;
				}
			}
			else
			{
				int ans=i/n+1;
				if(ans%2==1)
				{
					if(i%n==0) cout <<ans<<" "<<n;
					else cout <<ans<<" "<<i%n;
				}
				else
				{
					if(i%n==0) cout <<ans<<" "<<n;
					else cout <<ans<<" "<<n-(i%n)+1;
				}
			}
		}
	}
	return 0;
}
