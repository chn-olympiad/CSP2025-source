#include<bits/stdc++.h>
using namespace std;
int T,N;
int A[100011][3];
long long D[100011][3];
priority_queue<int>q[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<3;j++)
			{
				int t;
				cin>>t;
				q[j].push(t);
			}
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<3;j++)
			{
				D[i][j]=D[i-1][j]+q[j].top();
				q[j].pop();
			}
		}
		long long ans=0;
		for(int i=0;i<=N/2;i++)
		{
			for(int j=N/2-i;j<=N/2;j++)
			{
//				cout<<i<<" "<<j<<" "<<N-i-j<<endl;
				ans=max(ans,D[i][0]+D[j][1]+D[N-i-j][2]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
