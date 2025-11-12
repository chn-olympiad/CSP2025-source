#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define itn int
#define ing int
#define endl '\n'
using namespace std;

/*
ll mi(ll a,ll b,ll c)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans*=a;
		}
		ans%=c;
		a*=a;
		a%=c;
		b>>=1;
	}
	return ans;
}
*/
/*
bool cmp(int x,int y)
{
	return x>y;
}
*/

//int n,m;
//const int N=1e6+5;

//vector<int>e[N];

//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int t;
int n;
//int f[100005][4][500002];
struct node
{
	int first,second,third;
}a[100005];
//int f[10005][4][505];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int s[4];
	while(t--)
	{
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			
//			for(int k=1;k<=n/2;k++)
			//f[i][j][k]=INT_MIN;
			cin>>s[0]>>s[1]>>s[2];
			sort(s,s+3);
			a[i].first=s[2];
			a[i].second=s[1];
			a[i].third=s[0];
			
			 
		}
		
		if(n==2)cout<<a[1].first+a[2].first;
		
//		f[1][1][1]=a[1][1];
//		f[1][2][1]=a[1][2];
//		f[1][3][1]=a[1][3];
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=3;j++)
//			{
//				for(int k=1;k<=n/2;k++)
//				{
//					f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i][j]);
//					cout<<f[i][j][k]<<" ";
//				}
//				
//			}
		}
//		int ans=INT_MIN;
//		for(int i=1;i<=3;i++)
//		for(int j=1;j<=n/2;j++)
//		ans=max(ans,f[n][i][j]);
//		cout<<ans<<endl;
	
	
	return 0;
}










//		for(int j=1;j<=3;j++)
//			{
//				
//				for(int k=1;k<=n/2;k++)
//				f[1][j][k]=INT_MIN;
//			 } 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=3;j++)
//		{
//			
//			f[i+1][j][k]=max(f[i+1][j],f[i][j]+a[i][j]);
//		}
//	}
//	int ans=INT_MIN;
//	for(int i=1;i<=3;i++)
//	{
//		ans=max(ans,f[n+1][i]);
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=3;j++)cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
