#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans,dp[35][35][35][3];
struct Stu{
	int a[3];
}stu[100005];
bool cmp(Stu A,Stu B)
{
	return A.a[0]>B.a[0];
}
bool cmp2(Stu A,Stu B)
{
	return abs(A.a[0]-A.a[1])<abs(B.a[0]-B.a[1]);
}
bool cmp3(Stu A,Stu B)
{
	int AA=min(abs(A.a[0]-A.a[1]),abs(A.a[0]-A.a[2]));
	int BB=min(abs(B.a[0]-B.a[1]),abs(B.a[0]-B.a[2]));
	return AA<BB;
}
bool cmp4(Stu A,Stu B)
{
	int AA=min(abs(A.a[0]-A.a[1]),abs(A.a[1]-A.a[2]));
	int BB=min(abs(B.a[0]-B.a[1]),abs(B.a[1]-B.a[2]));
	return AA<BB;
}
bool cmp5(Stu A,Stu B)
{
	int AA=min(abs(A.a[2]-A.a[1]),abs(A.a[0]-A.a[2]));
	int BB=min(abs(B.a[2]-B.a[1]),abs(B.a[0]-B.a[2]));
	return AA<BB;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		bool flagA=1,flagB=1;
		for(int i=1;i<=n;i++)
		{
			cin>>stu[i].a[0]>>stu[i].a[1]>>stu[i].a[2];
			if(stu[i].a[1]!=0 || stu[i].a[2]!=0) flagA=0;
			if(stu[i].a[2]!=0) flagB=0;
		}
		if(flagA)
		{
			sort(stu+1,stu+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=stu[i].a[0];
			cout<<ans<<endl;
			continue;
		}
		else if(n<=30)
		{
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++)
				for(int aa=0;aa<=min(i-1,n/2);aa++)
					for(int bb=0;bb<=min(i-1,n/2) && bb+aa<=i-1;bb++)
					{
						int maxi1=max(dp[i-1][aa][bb][0],max(dp[i-1][aa][bb][1],dp[i-1][aa][bb][2]));
						dp[i][aa+1][bb][0]=max(dp[i][aa+1][bb][0],maxi1+stu[i].a[0]);
						dp[i][aa][bb+1][1]=max(dp[i][aa][bb+1][1],maxi1+stu[i].a[1]);
						dp[i][aa][bb][2]=max(dp[i][aa][bb][2],maxi1+stu[i].a[2]);
					}
			for(int i=1;i<=n/2;i++)
				for(int j=n/2-i;j<=n/2;j++)
					ans=max(ans,max(dp[n][i][j][0],max(dp[n][i][j][1],dp[n][i][j][2])));
			cout<<ans<<endl;
			continue;
		}
		else if(flagB)
		{
			vector <Stu> v1;
			vector <Stu> v2;
			v1.clear();
			v2.clear();
			for(int i=1;i<=n;i++)
				if(stu[i].a[0]>stu[i].a[1])
				{
					v1.push_back(stu[i]);
					ans+=stu[i].a[0];
				}
				else
				{
					v2.push_back(stu[i]);
					ans+=stu[i].a[1];
				}
//			cout<<ans<<' '<<v1.size()<<' '<<v2.size()<<' '<<endl;
			if(v1.size()>v2.size())
			{
				sort(v1.begin(),v1.end(),cmp2);
				for(int i=0;i<(v1.size()-v2.size())/2;i++)
					ans-=v1[i].a[0]-v1[i].a[1];
			}
			else if(v2.size()>v1.size())
			{
				sort(v2.begin(),v2.end(),cmp2);
				for(int i=0;i<(v2.size()-v1.size())/2;i++)
					ans-=v2[i].a[1]-v2[i].a[0];
			}
//			for(Stu u : v1) cout<<u.a[0]<<' '<<u.a[1]<<endl;
//			for(Stu u : v2) cout<<u.a[0]<<' '<<u.a[1]<<endl;
			cout<<ans<<endl;
			continue;
		}
		else
		{
			vector <Stu> v1;
			vector <Stu> v2;
			vector <Stu> v3;
			v1.clear();
			v2.clear();
			v3.clear();
			for(int i=1;i<=n;i++)
				if(stu[i].a[0]>max(stu[i].a[1],stu[i].a[2]))
				{
					v1.push_back(stu[i]);
					ans+=stu[i].a[0];
				}
				else if(stu[i].a[1]>max(stu[i].a[0],stu[i].a[2]))
				{
					v2.push_back(stu[i]);
					ans+=stu[i].a[1];
				}
				else
				{
					v3.push_back(stu[i]);
					ans+=stu[i].a[2];
				}
			
			
			if(v1.size()>n/2)
			{
				sort(v1.begin(),v1.end(),cmp3);
				for(int i=0;i<v1.size()-n/2;i++)
					ans-=v1[i].a[0]-max(v1[i].a[1],v1[i].a[2]);
				
			}
			else if(v2.size()>n/2)
			{
				sort(v2.begin(),v2.end(),cmp4);
				for(int i=0;i<v2.size()-n/2;i++)
					ans-=v2[i].a[1]-max(v2[i].a[2],v2[i].a[0]);
			}
			else if(v3.size()>n/2)
			{
				sort(v3.begin(),v3.end(),cmp5);
				for(int i=0;i<v3.size()-n/2;i++)
					ans-=v3[i].a[2]-max(v3[i].a[1],v3[i].a[0]);
			}
//			for(Stu u : v1) cout<<u.a[0]<<' '<<u.a[1]<<' '<<u.a[2]<<endl;
//			cout<<endl;
//			for(Stu u : v2) cout<<u.a[0]<<' '<<u.a[1]<<' '<<u.a[2]<<endl;
//			cout<<endl;
//			for(Stu u : v3) cout<<u.a[0]<<' '<<u.a[1]<<' '<<u.a[2]<<endl;
//			cout<<endl;
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}