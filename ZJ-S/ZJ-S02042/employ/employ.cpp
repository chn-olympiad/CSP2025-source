#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n,m;
string s;
vector<int>d;
int bit[505];
int a[505];
int vis[505];
int jsq=0;
long long jc[505]={1,1};
long long ans=0;
vector<int>tak;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int nows)
{
	long long sum=1;
//	cout<<nows<<endl;
	if(tak.size()==m)
	{	
		for(int i=tak.size()-1;i>=0;i--)
		{
			if(bit[tak[i]]==0)
			{
				sum=(sum*(bit[tak[i]]-(tak.size()-1)))%MOD;
			}
		}
		sum=sum*jc[n-m]%MOD;
		ans=(ans+sum)%MOD;
		return;
	}
	if(nows==d.size())
	{
		return;
	}
	tak.push_back(d[nows]);
	dfs(nows+1);
	tak.pop_back();
	dfs(nows+1);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; 
	for(int i=1;i<=500;i++)
	{
		jc[i]=jc[i-1]*i%MOD;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			d.push_back(i-d.size());
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bit[0]++;
		bit[a[i]]--;
	}
	for(int i=1;i<=n;i++)
	{
		bit[i]+=bit[i-1];
	}
//	cout<<"1 size is"<<d.size()<<endl;
	dfs(0);
	cout<<ans;
	return 0;
}