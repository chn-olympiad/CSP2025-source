#include<bits/stdc++.h>
using namespace std;
const int N=503;
const long long wh=998244353; 
int n,m,a[N],pre[N],u[N];
long long ans;
//__int128 an=1;
//bool flag=0;
string s; 
int t[N];
void dfs(int noww,int minn,int numm)
{
	if(noww==n+1)
	{
		if(numm>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!t[i])
		{
			t[i]=noww;
			if(s[i]=='0' || a[i]<=minn)
				dfs(i+1,minn+1,numm);
			else
				dfs(i+1,minn,numm+1);
			t[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
			pre[i+1]=pre[i]+1;
	}////////////////////////////////
//	if(!pre[n])
//	{
//		for(int i=n;i>1;i--)
//		{
//			an*=i;
//			an%=wh;
//		}
//		ans=(long long)an;
//		cout<<ans<<endl;
//	}////////////////////////////////
//	else if(m>n-pre[n])
//	{
//		cout<<0<<endl;
//	}///////////////////////////////
//	else if(m==1)
//	{
//		int cnt;
//		for(int i=0;i<n;i++)
//		{
//			if(s[i]=='1')
//			{
//				cnt=pre[i];
//				break;
//			}
//		}
//		an=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]>cnt)
//			{
//				an++;
//			}
//		}
//		for(int i=n-1;i>1;i++)
//		{
//			an*=i;
//			an%=wh;
//		}
//		ans=(long long)an;
//		cout<<ans<<endl;
//	}/////////////////////////////////
//	else
//	{
		dfs(1,0,0);
		cout<<ans<<endl;
//	}
	return 0;
}
