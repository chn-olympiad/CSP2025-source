#include<bits/stdc++.h>
using namespace std;
const int maxn=505,mod=998244353;
int n,m,c[maxn],a[maxn];
string s;
bool p1,p2=true;
void solveM_N()
{
	if(p1)
	{
		puts("0");
		return;
	}
	long long ans=1;
	for(int i=0;i<n;i++)
	{
		ans=ans*(i+1)%mod;
		if(s[i]=='0')
		{
			puts("0");
			return;
		}
	}
	cout<<ans<<endl;
}
void solveM_1()
{
	if(p2)
	{
		puts("0");
		return;
	}
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			flag=true;
			break;
		}
	}
	if(!flag)
	{
		puts("0");
		return;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
			p1=1;
		if(c[i]!=0)
			p2=0;
		a[i]=i;
	}
	if(m==n)
	{
		solveM_N();
		return 0;
	}
	/*
	if(m==1&&n>10)
	{
		solveM_1();
		return 0;
	}*/
	int ans=0;
	do{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a[i]<<" ";
//		}
	//	cout<<endl;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
				cnt++;
			else
			{
				if(cnt>=c[a[i]])
					cnt++;
			}
		}
		if(n-cnt>=m)
		{
			//cout<<"Yes"<<endl;
			ans++;
			if(ans>=mod)
				ans-=mod;
		}
		//else
			//cout<<"No"<<endl;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<endl;
	return 0;
}//12pts
