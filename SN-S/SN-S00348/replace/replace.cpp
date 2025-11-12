// xt66666
// 别挂分求你了CCF
//让我拿O(logn*L*L)的25分吧我爱你CCF 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,q;
map<string,string> v;
string s[200010];
string ss[200010];
//vector<pair<ll,ll> >[400010];
void fangan1()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];
		v[s[i]]=ss[i];
	}
	while(q--)
	{
		ll ans=0;
		string t1,t2;
		cin>>t1>>t2;
		ll l1=t1.size(),l2=t2.size();
		if(l1!=l2)
		{
			cout<<0<<endl;
			continue;
		}
		ll l,r;
		for(int i=0;i<l1;i++)
		{
			if(t1[i]!=t2[i])
			{
				l=i;
				break;
			}
		}
		for(int i=l1-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				r=i;
				break;
			}
		}
		for(int i=l;i>=0;i--)
		{
			string now="",nto="";
			for(int j=i;j<=r;j++)
			{
				now+=t1[j];
				nto+=t2[j];
			}
			if(v.count(now))
			{
				if(v[now]==nto)
				{
					ans++;
				}
			}
			for(int j=r+1;j<l1;j++)
			{
				now+=t1[j];
				nto+=t2[j];
				if(v.count(now))
				{
					if(v[now]==nto)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	fangan1();
	return 0;
	//没办法了 
	/*
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		cin>>ss[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1;
		cin>>t2;
	}*/
	//return 0;
}

