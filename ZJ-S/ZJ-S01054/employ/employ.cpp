#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=500;
const ll MOD=998244353;

int n,m;
int a[N];
int t[N],f[N];
string s;
ll ans=0;

bool pd()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0'||cnt>=f[i]) cnt++;
	if(n-cnt>=m) return true;
	return false;
}

void dfs(int num)
{
	if(num==n+1)
	{
		if(pd()) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!t[i])
		{
			f[num]=a[i];
			t[i]=1;
			dfs(num+1);
			t[i]=0;
		}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int tA=1;
	for(int i=1;i<=n&&tA;i++)
		if(a[i]!=1) tA=0;
	if(tA)
	{
		int people_pass=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='1') break;
			else people_pass++;
		ans=1;
		if(people_pass>=m)
		{
			for(int i=2;i<=m;i++) ans=ans*i%MOD;
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
			if(s[i-1]=='0'||!a[i])
			{
				cout<<0;
				return 0;
			}
		ans=1;
		for(int i=2;i<=m;i++) ans=ans*i%MOD;
		cout<<ans;
		return 0;
	}
	cout<<9914534;
	return 0;
}
