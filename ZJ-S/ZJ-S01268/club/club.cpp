#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int> v;
int a[100005][4];
long long f[205][205];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
		}
		if(!flag)
		{
			v.clear();
			for(int i=1;i<=n;i++) v.push_back(a[i][1]);
			sort(v.begin(),v.end(),cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++) sum+=v[i-1];
			cout << sum << "\n";
			continue;
		}
		memset(f,0,sizeof(f));
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=min(i,n/2);j>=0;j--)
			{
				for(int k=min(i-j,n/2);k>=0;k--)
				{
					int l=i-j-k;
					if(l>n/2) continue;
					if(l) f[j][k]=max(f[j][k],f[j][k]+a[i][3]);
					if(j) f[j][k]=max(f[j][k],f[j-1][k]+a[i][1]);
					if(k) f[j][k]=max(f[j][k],f[j][k-1]+a[i][2]);
					if(i==n) ans=max(ans,f[j][k]);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
