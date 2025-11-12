// 许景焱 SN-S00654 西安铁一中滨河高级中学
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn=500;
const int mod=998244353;

char ch;
int n,m,p[maxn+5],sta[maxn+5];
bool ac[maxn+5];
long long jc[maxn+5][2],ans=0;

int qpow(int base,int power)
{
	if(power==0)
		return 1;
	if(power==1)
		return base;
	long long temp=qpow(base,power>>1);
	temp=temp*temp%mod;
	if(power&1)
		return temp*base%mod;
	return temp;
}
bool check(int accept,int depth)
{
	if(accept>=m)
		return true;
	if(depth>n)
		return false;
	if(n-depth+1<m-accept)
		return false;
	if(depth-1-accept>=sta[p[depth]]||!ac[depth])
		return check(accept,depth+1);
	return check(accept+1,depth+1);
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	jc[0][0]=jc[0][1]=1;
	for(int i=1; i<=n; i++)
	{
		cin>>ch;
		ac[i]=ch-'0';
		p[i]=i;
	}
	for(int i=1; i<=n; i++)
		cin>>sta[i];
	do
	{
		if(check(0,1))
		{
			ans++;
			if(ans==mod)
				ans=0;
		}
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
