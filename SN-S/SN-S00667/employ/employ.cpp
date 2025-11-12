#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 505;
const int mod = 998244353;
int n,m,a[N],p[N],b[N],c[N];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	char ch;
	for(int i=1;i<=n;i++) 
	{
		cin>>ch;
		b[i]=ch-'0';
		p[i]=i;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	
	//for(int i=1;i<=n;i++) cout<<b[i]<<' ';
	//cout<<'\n';
	
	int ans=0;
	do
	{
		//for(int i=1;i<=n;i++) cout<<p[i]<<' ';
		int tmp=0,pas=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<tmp<<' '<<c[i]<<'\n';
			if(tmp>=c[p[i]]) tmp++;
			else
			{
				if(b[i]) pas++;
				else tmp++;
			}
		}
		//cout<<pas<<" "<<tmp<<endl;
		if(pas>=m) ans=(ans+1)%mod;
		//if(pas>=m) cout<<"YES"<<' ';
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n"; 
	return 0;
} 
