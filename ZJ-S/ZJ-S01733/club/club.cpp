#include<bits/stdc++.h>
using namespace std;
int ans,t,n,s[10003],MAX[10003],f[203][203];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	srand(time(0));
	cin>>t;
	while(t--)
	{
		cin>>n;
//		n=5;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=-1;
		f[0][0]=0;
		for(int i=1;i<=n;i++)
//		{
//			s[i*3]=rand()%6;
//			s[i*3+1]=rand()%6;
//			s[i*3+2]=rand()%6;
//		}
		cin>>s[i*3]>>s[i*3+1]>>s[i*3+2];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=n/2;j>=0;j--)
				for(int k=n/2;k>=0;k--)
					if(f[j][k]!=-1)
					{
						if(j<n/2)
							f[j+1][k]=max(f[j+1][k],f[j][k]+s[i*3]);
						if(k<n/2)
							f[j][k+1]=max(f[j][k+1],f[j][k]+s[i*3+1]);
						if(i-(j+k)<=n/2)
							f[j][k]=max(f[j][k],f[j][k]+s[i*3+2]);
						else
							f[j][k]=-1;
					}
//			for(int k=0;k<=n/2;k++)
//			{
//				for(int j=0;j<=n/2;j++)
//					cout<<f[j][k]<<' ';
//				cout<<'\n';
//			}
//			cout<<'\n';
		}
		for(int j=n/2;j>=0;j--)
			for(int k=n/2;k>=0;k--)
				ans=max(ans,f[j][k]);
//		for(int j=0;j<=n/2;j++)
//		{
//			for(int k=0;k<=n/2;k++)
//				cout<<f[j][k]<<' ';
//			cout<<'\n';
//		}
//		int t=ans;
//		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
//		if(ans!=t)
//		{
//			cout<<n<<'\n';
//			for(int i=1;i<=n;i++)
//				cout<<s[i*3]<<' '<<s[i*3+1]<<' '<<s[i*3+2]<<'\n';
//			return 0;
//		}
	}
	return 0;
}//chzxlfw AK IOI!
/*
5
2 2 5
4 5 2
0 2 5
2 4 4
4 5 5
*/
