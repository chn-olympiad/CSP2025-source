#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,a[5005];
bool b[5005];
long long cnt=0;
//void dfs(int k,int f,int id)
//{
//	if(k>=2)
//	{
//		cout << cnt << endl;
//		if(cnt>f)
//		{
//			cout << id << " " << cnt << endl;
//			ans=(ans+1)%998244353;
//		}
//	}
//	for(int j=1;j<id;j++)
//	{
//		if(b[j]==0)
//		{
//			for(int q=0;q<2;q++)
//			{
//			cout << "*************";
//				if(q==0)
//				{
//					b[j]=1;
//					dfs(k+1,f,id);
//					b[j]=0;
//				}
//				if(q==1)
//				{
//					
//					b[j]=1;
//					cnt+=a[j];
//					dfs(k+1,f,id+1);
//					cnt-=a[j];
//					b[j]=0;
//				}
//			}	
//		}
//	}
//}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool b=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)
		{
			b=1;
		}
	}
	if(n==3)
	{
		long long maxx=-1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
			cnt+=a[i];
		}
		if(cnt>maxx*2) cout << "1";
		else cout << "0";
		return 0;
	}
	if(!b)
	{
		long long sum=0;
		for(int i=3;i<=n;i++)
		{
			int j=i;
			long long cnt1=1,cnt2=1;
			for(int j=0;j<=i-1;j++)
			{
				cnt1*=(n-j);
				cnt2*=(j+1);
			}
			sum=(sum+cnt1/cnt2)%998244353;
		}
		cout << sum;
		return 0;
	}
//	sort(a+1,a+1+n);
//	for(int i=3;i<=n;i++)
//	{
//		dfs(0,a[i],i);
//	}
	cout << ans;
}
