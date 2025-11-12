#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int read()
{
	int num=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') sign=(ch=='-' ? -1:1),ch=getchar();
	while(ch>='0'&&ch<='9') num=(num<<1)+(num<<3)+ch-48,ch=getchar();
	return sign>0 ? num:-num;
}
struct line
{
	int l,r;
	bool operator<(const line& rhs) const {return l==rhs.l ? r<rhs.r:l<rhs.l;}
};
vector <line> ls;
int n,a[500020],k,pfx[500020];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	bool f1=true,f2=true;
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		pfx[i]=pfx[i-1]^a[i];
		if(a[i]!=1) f1=false;
		if(a[i]!=1&&a[i]!=0) f2=false;
		cnt1+=a[i],cnt0+=!a[i];
	}
	if(f1) return cout<<n/2,0;
	else if(f2&&k==1) return cout<<cnt1,0;
	else if(f2)
	{
		int lx=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			lx=(a[i] ? lx+1:0);
			if(lx&&lx%2==0) cnt++;
		}
		cout<<cnt0+cnt;
	}
	else
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((pfx[j]^pfx[i-1])==k||(i==j&&a[i]==k)) ls.push_back({i,j});
		sort(ls.begin(),ls.end());
		int lastl=0,lastr=0;
		for(auto [l,r]:ls)
			if(l>lastr) ans++,lastl=l,lastr=r;
		cout<<ans;
	}
	return 0;
}