#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define pll pair<int,int>
#define ft first

const int N=508,p=998244353;
int n,m;
ull ans;
unordered_map<int,int> mp;
int qj[N],mx=0;
int x[N];
bool vis[N];

ull jc(int lm)
{
	ull t=1;
	for(int i=2;i<=lm;i++)
		t=(t*i)%p;
	return t;
}

void dfs(int t,int sm)
{
	if(t>mx)
	{
		if(sm>=m)
			ans=(ans+1)%p;
		return ;
	}
	if(sm+mx-t+1<m)
		return ;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(i<=qj[t])
				dfs(t+1,sm+1);
			else
				dfs(t+1,sm);
			vis[i]=0;
		}
	}
	return ;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
		mp[c]+=1;
	}
		
	memset(x,0x3f,sizeof(x));
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			cnt++;
			x[cnt]=i+1-cnt;
		}
	}
	x[++cnt]=1e9;
	for(auto i:mp)
	{
		int pos=(lower_bound(x+1,x+1+cnt,i.ft)-x)-1;
		if(pos)
			for(int j=1;j<=pos;j++)
				qj[j]+=i.second;
		mx=max(mx,pos);
	}
	
	if(cnt==n+1)
	{
		ans=jc(n);
		cout<<ans;
	}
	else
	{
		dfs(1,0);
		ans=(ans*jc(n-mx))%p;
		cout<<ans;
	}
	cout<<endl;
	return 0;
}
//996491788296388609
//4611686018427387904
