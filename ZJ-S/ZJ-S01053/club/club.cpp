#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
int n,v[5][100001];
void solve()
{
	int ans=0,tot1=0,tot2=0,tot3=0;
	memset(v,0,sizeof v);
	cin>>n;
	f(i,1,n)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int maxx=max(a,max(b,c));
		int minn=min(a,min(b,c));
		int mid=a+b+c-maxx-minn;
		int dis=maxx-mid;
		if(a==maxx)v[1][++tot1]=dis;
		else if(b==maxx)v[2][++tot2]=dis;
		else v[3][++tot3]=dis;
		ans+=maxx;
	}
	if(tot1>n/2)
	{
		sort(v[1]+1,v[1]+tot1+1);
		f(i,1,tot1-n/2)ans-=v[1][i];
	}
	else if(tot2>n/2)
	{
		sort(v[2]+1,v[2]+tot2+1);
		f(i,1,tot2-n/2)ans-=v[2][i];		
	}
	else if(tot3>n/2)
	{
		sort(v[3]+1,v[3]+tot3+1);
		f(i,1,tot3-n/2)ans-=v[3][i];		
	}
	cout<<ans<<endl;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}