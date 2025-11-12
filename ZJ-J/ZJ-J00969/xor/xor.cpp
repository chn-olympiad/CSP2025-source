//bqq miaomiaomiao
//100
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5,maxa=1<<21;
int a[maxn+10];
int s[maxn+10];
bool v[maxa+1];
vector<int>g[maxa+1];
int b[maxn+10];
int main()
{
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	g[0].push_back(0);
	int subc=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],s[i]=s[i-1]^a[i],v[s[i]]=1;
		if(a[i]>255)
		{
			subc=1;
		}
	}
	int ans=0;
	int nxt=0;
	int mx=0;
	if(subc)
	{
		for(int i=1;i<=n;i++)
		{
			g[s[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{	
			mx=max(mx,a[i]?(1<<(int)ceil(log2(a[i]+0.1)))-1:0);
			if(mx<k)
			{
				continue;
			}
			int x=s[i]^k;
	//		cout<<"i="<<i<<"  x="<<x<<"  nxt="<<nxt<<endl;
			if(!v[x])
			{
				continue;
			}
			int cnt=0;
			for(int j:g[x])
			{
				b[++cnt]=j;
			}
	//		cout<<endl<<cnt<<endl;
			int ez=lower_bound(b+1,b+cnt+1,nxt)-b;
	//		cout<<b[ez]<<endl;
			if(ez!=cnt+1&&b[ez]<=i-1)
			{
				ans++,nxt=i;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,a[i]?(1<<(int)ceil(log2(a[i]+0.1)))-1:0);
			if(mx<k)
			{
				continue;
			}
			int x=s[i]^k;
			if(!v[x])
			{
				continue;
			}
			for(int j=i-1;j>=nxt;j--)
			{
				if(x==s[j])
				{
					ans++,nxt=i;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}