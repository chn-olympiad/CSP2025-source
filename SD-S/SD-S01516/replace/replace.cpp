#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
#define int long long
bool startmb;
constexpr int N=2e5+5,V=5e6+5;
int n,q;

string s[N][2];

namespace solve1
{
	constexpr int p=131;
	unsigned long long l[N],r[N],x[N],y[N];
	__gnu_pbds::gp_hash_table<unsigned long long,bool> visl,visr;
	void solve()
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]==s[i][1]) continue;
			int k=s[i][0].length(),lp=0,rp=0;
			for(int j=0;j<k;j++) if(s[i][0][j]!=s[i][1][j]) {lp=j;break;}
			for(int j=k-1;j>=0;j--) if(s[i][0][j]!=s[i][1][j]) {rp=j;break;}
			for(int j=lp-1;j>=0;j--) l[i]=l[i]*p+s[i][0][j];
			for(int j=rp+1;j<k;j++) r[i]=r[i]*p+s[i][0][j];
			for(int j=lp;j<=rp;j++) x[i]=x[i]*p+s[i][0][j],y[i]=y[i]*p+s[i][1][j];
//			cout<<i<<' '<<lp<<' '<<rp<<' '<<s[i][0][1]<<' '<<s[i][1][1]<<endl;
		}
		while(q--)
		{
			string t1,t2;
			cin>>t1>>t2;
			if(t1.length()!=t2.length()) {cout<<0<<'\n';continue;}
			int k=t1.length(),lp=0,rp=0;
			unsigned long long xval=0,yval=0;
			for(int i=0;i<k;i++) if(t1[i]!=t2[i]) {lp=i;break;}
			for(int i=k-1;i>=0;i--) if(t1[i]!=t2[i]) {rp=i;break;}
			for(int i=lp;i<=rp;i++) xval=xval*p+t1[i],yval=yval*p+t2[i];
			visl[0]=visr[0]=1;
			unsigned long long lval=0,rval=0;
			for(int i=lp-1;i>=0;i--) lval=lval*p+t1[i],visl[lval]=1;
			for(int i=rp+1;i<k;i++) rval=rval*p+t1[i],visr[rval]=1;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(x[i]==xval&&y[i]==yval&&visl.find(l[i])!=visl.end()&&visr.find(r[i])!=visr.end())
				{
					ans++;
				}
			}
			cout<<ans<<'\n';
			visl.clear(),visr.clear();
		}
	}
}
//namespace solve2
//{
//	bool check()
//	{
//		for(int i=1;i<=n;i++)
//		{
//			bool flag=0;
//			int k=s[i][0].length();
//			for(int j=0;j<k;j++)
//			{
//				if(s[i][0][j]!='a')
//				{
//					if(s[i][0][j]=='b'&&flag==0) flag=1;
//					else return 0;
//				}
//			}
//			if(!flag) return 0;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			bool flag=0;
//			int k=s[i][1].length();
//			for(int j=0;j<k;j++)
//			{
//				if(s[i][1][j]!='a')
//				{
//					if(s[i][1][j]=='b'&&flag==0) flag=1;
//					else return 0;
//				}
//			}
//			if(!flag) return 0;
//		}
//	}
//	int p[N],l1[N],l2[N],r1[N],r2[N];
//	void solve()
//	{
//		for(int i=1;i<=n;i++)
//		{
//			
//		}
//	}
//}

bool endmb;
main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cerr<<((&endmb-&startmb)/1024.0/1024)<<'\n';
	cin.tie(0)->sync_with_stdio(false);
	double starttime=clock();
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	solve1::solve();
	cerr<<((clock()-starttime)/CLOCKS_PER_SEC)<<'\n';
	return 0;
}
//多测要清空
//测极端数据
//注意数组大小
//注意保留小数位数

