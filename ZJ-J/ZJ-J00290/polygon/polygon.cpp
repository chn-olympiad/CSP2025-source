	#include<bits/stdc++.h>
	#define int long long
	using namespace std;
	const int N=5001,M=998244353;
	int a[N],b[N],ans,n,h,a2[10];
	void dfs(int w,int sum)
	{
		if(w>=3)
		{
			if(sum>a[w]*2)
			{
				ans++;
				ans%=M;
//				for(int i=1;i<=h;i++)
//				{
//					cout<<a2[i]<<" ";
//				}
//				cout<<"\n";
			}
		}
		if(w==n)
		{
			return;
		}
//		h++;
//		a2[h]=w+1;
		dfs(w+1,sum+a[w+1]);
//		a2[h]=0;
//		h--;
		dfs(w+1,sum);
	}
	signed main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n>20)
		{
			for(int i=3;i<=n;i++)
			{
				int a1=1;
				for(int j=i+1;j<=n;j++)
				{
					a1=(a1*j/(n-j+1))%M;
				}
				ans+=a1;
				ans%=M;
			}
			cout<<ans%M;
			return 0;
			//n zhong qu i ge
			//n!/i!/(n-i)!
			//
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			b[i]=b[i-1]+a[i];
		}
		dfs(0,0);
		cout<<ans%M;
		return 0;
	}
	/*
	dp[][]i dao j gen bu bang
	i>=j+2
	d[i][j]=d[]
	ke yi da ji ge
	5
	2 2 3 8 10
	*/
