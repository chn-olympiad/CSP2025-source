#include<iostream>
#include<cmath>
using namespace std;
const int MOD=998244353;
int c[5100];
int bb[5];
string s;
int jyh[19][27000];
int cb[31];
int qy,sr;
int fun(int a)
{
	int c=0;
	for(int i=0;i<=a;i++)
	{
		c=c*2;
		c=c+cb[i]; 
	} 
	return c;
}
int dfs(int t,int S,int p)
{
//	cout<<t<<' '<<s<<endl;
	int ans=0;
	
	if(t>sr)
	{
		if(sr-S-p>=qy)
		{
			return 1;
		}
		return 0;
	}
//	if(jyh[t][fun(s.size()-1)]!=-1)
//	{
//		return jyh[t][fun(s.size())];
//	}
	if(S>=c[t]) return dfs(t+1,S,p+1);
	for(int i=0;i<s.size();i++)
	{
		if(cb[i]==0)
		{	cb[i]=1;
			if(int(s[i])=='1')
			{
				ans+=dfs(t+1,S,p);
				ans%=MOD;
			}
			else
			{
				ans+=dfs(t+1,S+1,p);
				ans%=MOD;
				
			}
			cb[i]=0;
		}
	}
	return ans;//jyh[t][fun(s.size())]=
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b,d,e,f,g;
	cin>>a>>b>>s;
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<=pow(1,s.size());j++)
		{
			jyh[i][j]=-1;
		}
		cin>>c[i];
	}
//	for(int i=0;i<s.size();i++)
//	{
//		bb[s[i]-'0']++;
//		cout<<bb[i];
//	}
//	swap(bb[1],bb[0]);
	sr=a;
	qy=b;
	cout<<dfs(1,0,0);
	return 0;
}