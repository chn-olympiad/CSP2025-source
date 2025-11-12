#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T,n; 
int c1[N];
int a[30][5];

struct point{
	int x,y,z,fm,sm,fid;
}p[N];

struct node{
	int fm,fid,sm,sid;
}np[N];

inline bool cmp(int a,int b) {return a>b;}

inline bool cmp1(point a,point b) {return a.fm>b.fm;}

inline bool cmp2(node a,node b) {return a.sm>b.sm;}

inline void clear() {for(int i=1;i<=n;i++) { p[i].x=0;p[i].y=0;p[i].z=0;}}

inline void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		ans+=p[i].x;
		c1[i]=p[i].y-p[i].x;
	}
	sort(c1+1,c1+n+1,cmp);
	for(int i=1;i<=n/2;i++) ans+=c1[i];
	cout<<ans<<"\n";
	return; 
}

inline void solve2()
{
	int ans=0;
	for(int i=1;i<=n;i++) {a[i][1]=p[i].x;a[i][2]=p[i].y;a[i][3]=p[i].z;}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			if(i==j) continue;
			ans=max(ans,a[1][i]+a[2][j]);
		}
	cout<<ans<<"\n";
	return ;
}

inline void solve3()
{
	int ans=0;
	for(int i=1;i<=n;i++) {a[i][1]=p[i].x;a[i][2]=p[i].y;a[i][3]=p[i].z;}
	for(int a1=1;a1<=3;a1++)
	for(int a2=1;a2<=3;a2++)
	for(int a3=1;a3<=3;a3++)
	for(int a4=1;a4<=3;a4++)
	{
		if(((a1==a2)&&(a1==a3))||((a1==a3)&&(a1==a4))||((a1==a2)&&(a1==a4))||((a2==a3)&&(a2==a4))||((a1==a2)&&(a1==a3)&&(a1==a4))) continue;
		ans=max(ans,a[1][a1]+a[2][a2]+a[3][a3]+a[4][a4]);	
	}
	cout<<ans<<"\n";
	return ;
}

inline void solve()
{
	sort(p+1,p+n+1,cmp1);
	int cnt[5];for(int i=1;i<=3;i++) cnt[1]=0;
	int ans=0;int sid;int tot=0;
	for(int i=1;i<=n;i++)
	{
		ans+=p[i].fm;
		cnt[p[i].fid]++;
		if(cnt[p[i].fid]>n/2) 
		{
			ans=ans-p[i].fm;
			cnt[p[i].fid]--;
			tot++;
			np[tot].fm=p[i].sm;
			if(p[i].sm==p[i].x) np[tot].fid=1;
			else if(p[i].sm==p[i].y) np[tot].fid=2;
			else np[tot].fid=3;
			sid=6-p[i].fid-np[tot].fid;
			np[tot].sid=sid;
			if(sid==1) np[tot].sm=p[i].x;
			else if(sid==2) np[tot].sm=p[i].y;
			else np[tot].sm=p[i].z;
		}
	}
	sort(np+1,np+tot+1,cmp2);
	for(int i=1;i<=tot;i++)
	{
		ans+=np[i].fm;
		cnt[np[i].fid]++;
		if(cnt[np[i].fid]>n/2) cnt[np[i].fid]--,ans=ans-np[i].fm+np[i].sm;
	}
	cout<<ans<<"\n";
	return ;
}

signed main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;	
		for(int i=1;i<=n;i++) 
		{
			cin>>p[i].x>>p[i].y>>p[i].z;
			p[i].fm=max(p[i].x,max(p[i].y,p[i].z));
			if(p[i].fm==p[i].x) p[i].sm=max(p[i].y,p[i].z),p[i].fid=1;
			else if(p[i].fm==p[i].y) p[i].sm=max(p[i].x,p[i].z),p[i].fid=2;
			else p[i].sm=max(p[i].x,p[i].y),p[i].fid=3; 
		}
		int fla=1;
		for(int i=1;i<=n;i++) {if(p[i].z) {fla=0;break;}}
		if(fla)
		{
			solve1();
			clear();
		}
		else if(n==2) {solve2();}
		else if(n==4) {solve3();}
		else solve();
		clear();
	}
	return 0;
} 
