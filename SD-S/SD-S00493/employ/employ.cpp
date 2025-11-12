#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],title[505],sum[505],minn=114514,ans;
int lll[505];
string s;
long long fac(long long n)
{
	long long res=1;
	for(int i=1;i<=n;i++) res=res*i%mod;
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		title[i]=s[i]-'0';
		minn=min(minn,title[i]);
		if(title[i]==0) sum[i]=sum[i-1]+1; 
		lll[c[i]]++;
	}
	if(minn==1)
	{
		if(n-lll[0]>=m) cout<<fac(n-lll[0]);
		else cout<<0;
	}
//	cout<<endl;
	else if(n<=10)
	{
		do
		{
			int cnt=0,summ=0;
			for(int i=1;i<=n;i++)
			{
				if((c[i]>summ)&&(title[i]==1))
				{
					cnt++;
				}
				else summ++;
//				cout<<c[i]<<' ';
			}
//			cout<<endl;
//			cout<<cnt<<" "<<summ<<endl;
			if(cnt>=m)
			{
				int x=1;
				for(int i=1;i<=n;i++) x*=pow(2,max(lll[i]-1,0));
				ans+=x;
			}
		}while(next_permutation(c+1,c+n+1));

		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//freopen
//love
//ccf
//mihoyo
//yuanshen
//fopen
//xuhuangliuqiang
