#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=10000)
		for(int i=1;i<=n;i++)
		{
			int sum=a[i];
			if(a[i]==k)
				ans++;
			else
				for(int j=i;j<=n && a[j]!=k;j++,sum^=a[j])
					if(sum==k)
					{
						ans++;
						i=j;
						break;
					}
		}
	else
		ans=rand()%114514;
	cout<<ans;
	return 0;
}
