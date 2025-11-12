#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Revi{
	const int N=5e5+5;
	struct tri
	{
		int x,y,z;
	}a[N];
	bool cmp(tri A,tri B)
	{
		int mxa,mxb;
		int cxa,cxb;
		if(A.x<=A.y&&A.y<=A.z) mxa=A.z,cxa=A.y;
		else if(A.x<=A.z&&A.z<=A.y) mxa=A.y,cxa=A.z;
		else if(A.z<=A.y&&A.y<=A.x) mxa=A.x,cxa=A.y;
		else if(A.z<=A.x&&A.x<=A.y) mxa=A.y,cxa=A.x;
		else if(A.y<=A.x&&A.x<=A.z) mxa=A.z,cxa=A.x;
		else if(A.y<=A.z&&A.z<=A.x) mxa=A.x,cxa=A.z;
		
		if(B.x<=B.y&&B.y<=B.z) mxb=B.z,cxb=B.y;
		else if(B.x<=B.z&&B.z<=B.y) mxb=B.y,cxb=B.z;
		else if(B.z<=B.y&&B.y<=B.x) mxb=B.x,cxb=B.y;
		else if(B.z<=B.x&&B.x<=B.y) mxb=B.y,cxb=B.x;
		else if(B.y<=B.x&&B.x<=B.z) mxb=B.z,cxb=B.x;
		else if(B.y<=B.z&&B.z<=B.x) mxb=B.x,cxb=B.z;
		
		return mxa-cxa<mxb-cxb;
	}
	int T,n;
	inline void work()
	{
		cin>>T;
		while(T--)
		{
			cin>>n;
			vector<tri> X,Y,Z; 
			for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
			for(int i=1;i<=n;i++)
			{
				int mx=max(a[i].x,max(a[i].y,a[i].z));
				if(a[i].x==mx) X.push_back(a[i]);
				else if(a[i].y==mx) Y.push_back(a[i]);
				else if(a[i].z==mx) Z.push_back(a[i]);
			}
			int mx=max(X.size(),max(Y.size(),Z.size()));
			int ans=0;
			for(tri i:X) ans+=i.x; 
			for(tri i:Y) ans+=i.y; 
			for(tri i:Z) ans+=i.z;
			if(mx<=n/2)
			{	
				cout<<ans<<"\n";
				continue; 
			}
			if(X.size()>n/2)
			{
				sort(X.begin(),X.end(),cmp);
				for(int i=1;i<=X.size()-n/2;i++)
				{
					if(X[i-1].y>=X[i-1].z) ans-=X[i-1].x,ans+=X[i-1].y;
					else if(X[i-1].y<=X[i-1].z) ans-=X[i-1].x,ans+=X[i-1].z;
				}	
				cout<<ans<<"\n";
				continue;			
			}
			if(Y.size()>n/2)
			{
				sort(Y.begin(),Y.end(),cmp);
				for(int i=1;i<=Y.size()-n/2;i++)
				{
					if(Y[i-1].x>=Y[i-1].z) ans-=Y[i-1].y,ans+=Y[i-1].x;
					else if(Y[i-1].x<=Y[i-1].z) ans-=Y[i-1].y,ans+=Y[i-1].z;
				}	
				cout<<ans<<"\n";
				continue;			
			}
			if(Z.size()>n/2)
			{
				sort(Z.begin(),Z.end(),cmp);
				for(int i=1;i<=Z.size()-n/2;i++)
				{
					if(Z[i-1].x>=Z[i-1].y) ans-=Z[i-1].z,ans+=Z[i-1].x;
					else if(Z[i-1].x<=Z[i-1].y) ans-=Z[i-1].z,ans+=Z[i-1].y;
				}	
				cout<<ans<<"\n";
				continue;			
			}
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Revi::work();
	return 0;
 } 
 
 
 /*
 
 
33min ,
 
 */
