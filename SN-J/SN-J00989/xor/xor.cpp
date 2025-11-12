#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
const int inf=1e9+7;
int n,k;
int a[MAXN],q[MAXN];

int dp[MAXN];
void Max(int &a,int b)
{
	if(b>a) a=b;
}
int get(int l,int r)
{
	return (q[r]^q[l-1])==k;
}


//int mx[MAXN<<2],ad[MAXN<<2];
//vector<int> w[MAXN<<2];
//
//#define mid ((l+r)>>1)
//#define ls (i<<1)
//#define rs (i<<1|1)
//void up(int i)
//{
//	mx[i]=max(mx[ls],mx[rs]);
//	w[i].clear();
//	if(mx[ls]>=mx[rs]) w[i]=w[ls];
//	if(mx[rs]>=mx[ls])
//	{
//		for(auto d:w[rs]) w[i].push_back(d);
//	}
//}
//
//void dn(int i)
//{
//	if(ad[i]==0) return ;
//	mx[ls]+=ad[i];
//	mx[rs]+=ad[i];
//	ad[ls]+=ad[i];
//	ad[rs]+=ad[i];
//	ad[i]=0;
//}
//
//void bu(int i,int l,int r)
//{
//	if(l==r)
//	{
//		mx[i]=ad[i]=0;
//		return ;
//	}
//	bu(ls,l,mid);
//	bu(rs,mid+1,r);
//	up(i);
//}
//
//void Iins(int i,int l,int r,int w,int k)
//{
//	if(l==r)
//	{
//		ad[i]+=k;
//		mx[i]+=k;
//		return ;
//	}
////	dn(i)
//	if(w<=mid) Iins(ls,l,mid,w,k);
//	if(mid+1<=w) Iins(rs,mid+1,r,w,k);
//	up(i); 
//} void ins(int w,int k) {Iins(1,1,n,w,k);}
//
//pair<int,vector<int>> Iget(int i,int l,int r,int L,int R)
//{
//	if(L<=l&&r<=R)
//	{
//		return{mx[i],{i}};
//	}
//	dn(i);
//	int ans=-inf;
//	vector<int> ww;
//	if(L<=mid) 
//	{
//		pair<int,vector<int>> now=Iget(ls,l,mid,L,R);
//		if(now.first>=ans)
//		{
//			ans=now.first;
//			ww=now.second;
//		}
//	}
//	if(mid+1<=R) 
//	{
//		pair<int,vector<int>> now=Iget(rs,mid+1,r,L,R);
//		if(now.first>=ans)
//		{
//			ans=now.first;
//			for(auto d:now.second) ww.push_back(d);
//		}
//	}
//	return {ans,ww};
//} pair<int,vector<int>> myget(int l,int r) {return Iget(1,1,n,l,r);}



signed main()
{
	freopen("xor.in","r",stdin);
	freopen("out.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	
//	bu(1,1,n);
//	
//	ins(1,3,4);
//	cout<<myget(1,4)<<endl;
//	ins(1,1,1);
//	ins(2,2,-1);
//	ins(3,3,3);
//	cout<<myget(1,4)<<endl;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) q[i]=q[i-1]^a[i];

	dp[1]=get(1,1);
	
	for(int i=1;i<=n;i++)
	{
//		pair<int,vector<int>> now=myget(1,i-1);
//		int maxx=0;
//		for(auto &d:now.second)
//		{
//			maxx=max(maxx,d+get(d,i-1));
//		}
//		dp[i]=maxx;
//		ins(i,dp[i]);
		
		for(int j=1;j<=i;j++)
		{
			Max(dp[i],dp[j-1]+get(j,i));	
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++) cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	
	cout<<dp[n];
	return 0;
}


/*
4 2
2 1 0 3


4 3
2 1 0 3

*/
