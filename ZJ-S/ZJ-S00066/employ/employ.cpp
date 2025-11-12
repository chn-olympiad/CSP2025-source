#include<bits/stdc++.h>
using namespace std;
const int N=505,P=998244353;
int frac[N],n,m,c[N],p[N];
char s[N];
bool SpA=true;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;cin>>s+1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];p[i]=i;
		if(s[i]!='1') SpA=false;
	}
	frac[1]=1;
	for(int i=2;i<=n;i++)
		frac[i]=(1ll*frac[i-1]*i)%P;
	if(m==n)//all employed
	{
		if(SpA) cout<<frac[n];
		else cout<<0;
		return 0;
	}
	if(SpA)//all accepted
	{
		for(int i=1;i<=n;i++)
			cout<<frac[i]<<' ';
		cout<<endl;
		cout<<frac[n];
		return 0;
	}
	int ans=0;
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[p[i]]||s[i]=='0') cnt++;
			if(cnt>n-m) break;
		}
		if(cnt<=n-m) ans=(ans+1)%P;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
