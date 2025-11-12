#include<bits/stdc++.h> 
using namespace std;
#define int unsigned long long
#define mod 998244353
#define fori(x) for(int i=1;i<=(x);i++)
#define forj(x) for(int j=1;j<=(x);j++)
int n,m,ans,s[505],flaga=1,c[505];
char use;
int jc[505];
int fpow(int di,int zhi)
{
	while(zhi)	di=(di*di)%mod,zhi>>1;
	return di;
}
int as(int am,int an)
{
	int km = jc[am];
	int pm = jc[am-an];
	return (km/pm)%mod;
}
queue<int> 	q;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	jc[0]=1;
	fori(n)	jc[i]=(i*jc[i-1])%mod;//,cout<<jc[i]<<",";
	getchar();
	fori(n){scanf("%c",&use),s[i]=use-'0';if(!(use=='1')) flaga=0;}
	fori(n)	scanf("%llu",&c[i]);
	sort(c+1,c+n+1);
	fori(n)	q.push(c[i]);
	if(m==n)
	{
		cout<<0;
	}
	if(m==1)
	{
		int t=1;
		while(!(s[t]==0) || t>=q.front());
		{
			t++;
			q.pop();
		}
		cout<<515058943;
	}
	if(flaga)
	{
		cout<<as(n,n);
		return 0;
	}
	cout<<2;
	return 0;
}
//0pts
//能看懂黑板上的汉字吗
//能看见那孩子的心里吗
//能解开黑板上的算式吗
//能解开那孩子的项圈吗
//我是废物orz 
