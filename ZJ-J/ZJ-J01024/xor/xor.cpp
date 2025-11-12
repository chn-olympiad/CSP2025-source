#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],r=1,ans=0,res,la=0;
bool f=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(r<=n)
	{
		res=a[r],f=0;
		for(int i=r;i>la;i--)
		{
			if(res==k)
			{
				f=1,la=r,r++,ans++;
				break;
			}
			res^=a[i-1];
		}
		if(!f)
			r++;
	}
	cout<<ans;
	return 0;
}
