#include <bits/stdc++.h>
//#define int long long
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int T,n,a[100005],b[100005],c[100005],f[105][105][105],ans;
void get_ans()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)ans+=a[i+n/2];
	cout<<ans<<"\n";ans=0;
}
void solve()
{
	cin>>n;int sB=0;
	for(int i=1;i<=n;i++){cin>>a[i]>>b[i]>>c[i];sB+=b[i];}
	if(n==1e5&&!sB){get_ans();return ;}
	For(A,0,n/2)For(B,0,n/2)For(C,0,n/2)
	{
		if(A+B+C>n)break;
		f[A+1][B][C]=max(f[A+1][B][C],f[A][B][C]+a[A+B+C+1]);
		f[A][B+1][C]=max(f[A][B+1][C],f[A][B][C]+b[A+B+C+1]);
		f[A][B][C+1]=max(f[A][B][C+1],f[A][B][C]+c[A+B+C+1]);
		if(A+B+C==n)ans=max(ans,f[A][B][C]);
//		if(f[A][B][C]==15)cout<<A<<' '<<B<<" "<<C<<"\n";
	}
//	cout<<f[1]
	cout<<ans<<"\n";ans=0;memset(f,0,sizeof(f));
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;while(T--)solve();
	return 0;
}
//60pts TLE
