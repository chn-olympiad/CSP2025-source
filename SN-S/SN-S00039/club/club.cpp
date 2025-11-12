#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,i,j,a[N][4],chs[N],s[N],c[N],cnt,t[4],q[N],top;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cnt=0,top=0;
		memset(t,0,sizeof(t));
		memset(chs,0,sizeof(chs));
		cin>>n;
		for(i=1;i<=n;i++) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			c[i]=1e8,cnt+=s[i];
			for(j=1;j<=3;j++)
			{
				if(a[i][j]==s[i]&&(!chs[i]))
				{
					chs[i]=j;
					t[j]++;
				}
				else c[i]=min(c[i],s[i]-a[i][j]);
			}
		}
		for(j=1;j<=3;j++) 
		{
			if(t[j]*2>n)
			{
				for(i=1;i<=n;i++) if(chs[i]==j) q[++top]=c[i];
				sort(q+1,q+1+top);
				for(i=1;t[j]*2>n;i++)
				{
					cnt-=q[i];
					t[j]--;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
