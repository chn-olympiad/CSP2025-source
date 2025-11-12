#include<bits/stdc++.h>
using namespace std;
int c[1000];
int n,m,on;
int check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=x-on+1)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	int ck=x;
	for(int i=n-1;i>0;i--)
	{
		ck--;
		if(ck<0)
		{
			break;
		}
		cnt*=i;
	}
	return cnt;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string st;
	cin>>st;
	int one=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==n){
		bool t=0;
		for(int i=0;i<int(st.size());i++)
		{
			if(st[i]=='0')
			{
				t=1;
			}
		}
		if(t==1)
		{
			cout<<0;
			return 0;
		}
		long long ret=1;
		for(int i=n;i>1;i--)
		{
			ret*=i;
			ret%=998244353;
		}
		cout<<ret;
		return 0;
	}
	else
	{
		long long ret=1;
		for(int i=n;i>1;i--)
		{
			ret*=i;
			ret%=998244353;
		}
		for(int i=0;i<int(st.size());i++)
		{
			if(st[i]=='1')
			{
				on++;
				ret-=check(i);
				while(ret<0)
				{
					ret+=998244353;
				}
			}
		}
		while(ret<0)
		{
			ret+=998244353;
		}
		cout<<ret;
	}
	return 0;
}
