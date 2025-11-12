#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string t[1000006][2],s[1000006][2];
int df_t[1000006],df_s[1000006];
const int mod=1e9+7,base=26;
int g_hash(string& s,int l,int r)
{
	int res=0;
	for(int i=l;i<=r;i++)
	{
		res=res*26+(s[i]-'a');
		res%=mod;
	}
	return res;
}
int P[1000006];
//int g_hash(vector<int> sum,int l,int r)
//{
//	int res=sum[r]-sum[l-1]*P[r-l+1]%mod;
//	return (res%mod+mod)%mod;
//}
vector<int> sum_s[1000006][2];
vector<int> sum_t[1000006][2];
int l[1000006],r[1000006];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	P[0]=1;
	for(int i=1;i<=1e6;i++)P[i]=P[i-1]*26%mod;
	
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	
	for(int i=1;i<=q;i++)
	{
		int lx=0;
		for(;;lx++)
		{
			if(t[i][0][lx]!=t[i][1][lx])
			{
				l[i]=lx;
				break;
			}
		}
		int rx=t[i][0].size()-1;
		for(;;rx--)
		{
			if(t[i][0][rx]!=t[i][1][rx])
			{
				r[i]=rx;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=0;j<s[i][0].size();j++)
		{
			res=res*26+(s[i][0][j]-'a');
			res%=mod;
			sum_s[i][0].push_back(res);
		}
		res=0;
		for(int j=0;j<s[i][1].size();j++)
		{
			res=res*26+(s[i][1][j]-'a');
			res%=mod;
			sum_s[i][1].push_back(res);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int res=0;
		for(int j=0;j<t[i][0].size();j++)
		{
			res=res*26+(t[i][0][j]-'a');
			res%=mod;
			sum_t[i][0].push_back(res);
		}
		res=0;
		for(int j=0;j<t[i][1].size();j++)
		{
			res=res*26+(t[i][1][j]-'a');
			res%=mod;
			sum_t[i][1].push_back(res);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i][0].size();j++)
		{
			if(s[i][0][j]!=s[i][1][j])
			{
				df_s[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<t[i][0].size();j++)
		{
			if(t[i][0][j]!=t[i][1][j])
			{
				df_t[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(df_t[i]>=df_s[j]&&t[i][0].size()-df_t[i]>=s[j][0].size()-df_s[j])
			{
				if((g_hash(t[i][0],df_t[i]-df_s[j],df_t[i]-df_s[j]+s[j][0].size()-1)
				==g_hash(s[j][0],0,s[j][0].size()-1))
				&&
				g_hash(t[i][1],df_t[i]-df_s[j],df_t[i]-df_s[j]+s[j][1].size()-1)
				==g_hash(s[j][1],0,s[j][1].size()-1)
				&&
				l[i]>=df_t[i]-df_s[j]
				&&r[i]<=df_t[i]-df_s[j]+s[j][0].size()-1
				)
				{
					cnt++;
					//cout<<j<<"j--\n"; 
				}
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}