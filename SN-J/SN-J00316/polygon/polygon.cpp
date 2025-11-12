//MS Attached to NWPU SN-J00316 Zhang Yuanhao
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
ll n,a[5003]={0},s=0,res=0;
ll qp(ll b)
{
	if(!b) return 1ll;
	ll ans=2*1ll;
	ll ans1=1ll;
	while(b>1)
	{
		if(b%2)
		{
			ans1*=ans;
			ans1%=p;
			b--;
		}
		else
		{
			ans=ans*ans;
			ans%=p;
			b>>=1;
		}
	}
	return (ans*ans1)%p;
}
//longest;short sum;remaining nums
void dfs(int pos,int sum,int rem)
{
	if(sum>a[pos])
	{
		res+=qp(rem-1);
		res%=p;
//		cerr << res << endl;
		return;
	} 
	if(rem<1) return;
	rem--;
	sum+=a[rem];
	dfs(pos,sum,rem);
	sum-=a[rem];
	dfs(pos,sum,rem);
	return;
}
ll C(int bs,int upp)
{
	if(upp>(bs/2))
		upp=bs-upp;
	ll crt=1;
	for(int i=bs;i>=bs-upp+1;i--)
	{
		crt*=i;
		crt%=p;
	}
	for(int i=1;i<=upp;i++)
		crt/=i;
	return crt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s+=a[i];
	}
	if(s==n)
	{
		int owo=0;
		for(int i=3;i<=n;i++)
			owo+=C(n,i);
		cout << owo << '\n';
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--)
	{
		dfs(i,0,i);
	}
	cout << res;
	return 0;
}
//notes:
//9:45 bu hui......QwQ
//9:51 BANGING STRIKE IN16.0 99.81% 1g2m
//9:55 you dian si lu le,hao xiang shi /bangbangt ti 
//9:58 xi xi f hao xiang he xiao gun guo bu qu
//10:35 why it outputs 14?????
//10:43 dfs code OK!!!!!!!!!!OvO
//10:52 but n=500 will T fly!
//10:53 n=100 will T fly too!
//10:55 pass cases:1-10,15-20,16 in total,64pts owo
//10:58 pass n=20!64pts pao lu 
//      gun qu xiang T3 qu le
