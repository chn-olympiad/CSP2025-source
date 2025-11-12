#include<bits/stdc++.h>
using namespace std;
long long t,n,u,v,w,ans,cnt;
long long a[100005][5],b[100005][5];
priority_queue<long long,vector<long long>,greater<long long> > s[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=3;i++)
		{
			while(!s[i].empty()) s[i].pop();
		}
		u=0,v=0,w=0,ans=0,cnt=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
			b[i][1]=min(a[i][1],min(a[i][2],a[i][3]));
			b[i][2]=a[i][1]+a[i][2]+a[i][3]-b[i][0]-b[i][1];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				u++;
				s[1].push(b[i][0]-b[i][2]);
			} 
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
			{
				v++;
				s[2].push(b[i][0]-b[i][2]);
			} 
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]) 
			{
				w++;
				s[3].push(b[i][0]-b[i][2]);
			}
			ans+=b[i][0];
		}
		while(u>n/2) cnt+=s[1].top(),s[1].pop(),u--;
		while(v>n/2) cnt+=s[2].top(),s[2].pop(),v--;
		while(w>n/2) cnt+=s[3].top(),s[3].pop(),w--;
		cout<<ans-cnt<<'\n';
	}
	return 0;
} 