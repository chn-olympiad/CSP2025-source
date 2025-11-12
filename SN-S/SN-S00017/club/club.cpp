//付黄旗正 SN-S00017 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],m[100005],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(m,0,sizeof(m));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			m[i]=a[i][1];
		}
		sort(m,m+n+1);
		for(int i=n;i>n/2;i--)
		{
			ans+=m[i];
		}
		cout<<ans;
	}
	return 0;
}
