	#include<bits/stdc++.h>
//	#define int long long
	using namespace std;
	const int N=1e6+1;
	int len,a[10],w,t;
	string s;
	bool cmp(int x,int y)
	{
		return x>y;
	}
	signed main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		cin>>s;
		len=s.size();
		for(int i=0;i<len;i++)
		{
			if(s[i]<='9'&&s[i]>='0')
			{
				a[s[i]-48]++;
				if(s[i]!='0')
				{
					t++;
				}
			}
		}
		if(t==0)
		{
			cout<<0;
			return 0;
		}
		else
		{
			for(int i=9;i>-1;i--)
			{
				for(int j=1;j<=a[i];j++)
				{
					cout<<i;
				}
			}
		}
		return 0;
	}
	/*
	290es1q0
	*/
