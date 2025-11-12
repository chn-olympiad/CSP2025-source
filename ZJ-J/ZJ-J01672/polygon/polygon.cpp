#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5100];
long long maxx=INT_MIN;
long long sum;
long long xs[5100],v,b[5100];
bool f[5100],fl;
long long ans;
long long C(long long shang,long long xia)
{
	if(shang>xia/2)return C(xia-shang,xia);
	long long s1,s2;
	s1=s2=1;
	long long u=shang;
	for(int i=1;i<=u;i++)
	{
		s1*=shang;
		s2*=xia;
		s1%=MOD;
		s2%=MOD;
		shang++;
		xia--;
	}
	return s2/s1%MOD;
}
void dfs(long long x,long long sx)
{
//	cout<<x<<" "<<sx<<":";
//	for(int i=1;i<=x;i++)cout<<xs[i];
//	cout<<endl;
	if(sx==0)
	{
		v++;
		for(int i=1;i<=x;i++)
		{
//			cout<<xs[i];
			b[v]=b[v]*10+xs[i];
		}
//		cout<<endl;
		return;
	}
//	return ;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0&&i>xs[x-sx])
		{
			f[i]=1;
			xs[x-sx+1]=i;
			dfs(x,sx-1);
//			cout<<"@";
			f[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	else if(n<=3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>maxx*2)
		{
			cout<<1;
			return 0;
		}
	}
//	dfs(4,4);
//	for(int i=1;i<=v;i++)cout<<b[i]<<endl;
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=1)fl=1;
		}
		if(fl==0)
		{
//			cout<<"$";
			for(int bs=3;bs<=n;bs++)
			{
				v=0;
				memset(f,0,sizeof(f));
				memset(xs,0,sizeof(xs));
				memset(b,0,sizeof(b));
//				dfs(bs,bs);
//				cout<<"$";
//				ans+=v;
				ans+=C(bs,n)%MOD;
				ans%=MOD;
			}
			cout<<ans;
			return 0;
		}
		for(int bs=3;bs<=n;bs++)
		{
			v=0;
			memset(f,0,sizeof(f));
			memset(xs,0,sizeof(xs));
			memset(b,0,sizeof(b));
			dfs(bs,bs);
			for(int i=1;i<=v;i++)
			{
//				cout<<b[i]<<":";
				sum=0;
				maxx=INT_MIN;
				for(int j=1;j<=bs;j++)
				{
					int t=b[i]%10;
					sum+=a[t];
					maxx=max(maxx,a[t]);
					b[i]/=10;
				}
				if(sum>maxx*2)
				{
//					cout<<sum<<" "<<maxx<<" / ";
//					cout<<'!'<<endl;
					ans++;
					ans%=MOD;
				}
//				else cout<<endl;
			}
		}
		cout<<ans;
	}
	return 0;
}
