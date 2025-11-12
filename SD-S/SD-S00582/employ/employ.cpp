#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M=998244353;
LL n,m,g[1000],st[20],a[20],ans,ss[1000];
string s;
LL jc(LL x)
{
	LL les=1;
	for(int i=1;i<=x;i++) les=les*i%M;
	return les;
}
void f(int cnt)
{
	if(cnt==n)
	{
		int les=0,w=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0') w++;
			else if(w>=a[i]) w++;
			else les++;
		}
		if(les>=m) ans++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(st[i]==0)
		{
			st[i]=1;
			a[cnt]=g[i];
			f(cnt+1);
			st[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>g[i];
	if(n<=18) f(0);
	else
	{
		sort(g,g+n);
		ans=1;
		for(int i=0;i<n;i++) ss[g[i]]++;
		LL cnt=n;
		for(int i=0;i<n;i++)
		{
			if(i!=0) ss[i]+=ss[i-1];
			if(s[i]=='1') 
			{
				ans=ans*(ss[i]+cnt-n)%M;
				cnt--;
			}
		}
		ans=ans*jc(cnt)%M;
		ans=(jc(n)-ans+M)%M;
	}
	cout<<ans;
	return 0;
} 
