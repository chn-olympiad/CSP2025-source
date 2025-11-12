#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int T,n,a[MAXN],b[MAXN],c[MAXN]; 
int maxx(int a,int b)
{
	if(a>b)return a;
	else return b; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2)
		{
			int maxn=0;
			maxn=maxx(maxn,maxx(a[1]+b[2],maxx(a[1]+c[2],maxx(a[2]+b[1],maxx(a[2]+c[1],maxx(b[2]+c[1],b[1]+c[2]))))));
			cout<<maxn<<"\n";
		}
		if(n==4)
		{
			int maxna,maxnna,maxnb,maxnnb,maxnc,maxnnc;
			for(int i=1;i<=n;i++)
			{
				maxna=maxx(a[i],maxna);
				maxnb=maxx(b[i],maxnb);
				maxnc=maxx(c[i],maxnc);
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=maxna)maxnna=maxx(a[i],maxnna);
				if(b[i]!=maxnb)maxnb=maxx(b[i],maxnb);
				if(c[i]!=maxnc)maxnc=maxx(c[i],maxnc);
			}
			int maax=maxx(maxna+maxnna,max(maxnb+maxnnb,maxnc+maxnnc));
			if(maax==(maxna+maxnna))cout<<maax+maxnb+maxnc<<"\n";
			if(maax==(maxnb+maxnnb))cout<<maax+maxna+maxnc<<"\n";
			if(maax==(maxnc+maxnnc))cout<<maax+maxnb+maxna<<"\n";
		}
	}
	return 0;
}
