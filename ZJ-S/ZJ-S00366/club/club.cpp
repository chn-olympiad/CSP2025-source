#include<bits/stdc++.h>
using namespace std;
int T,n,ta,tb,tc,ans,x,y,z;
struct node{int x,y,z;}Ta[100010],Tb[100010],Tc[100010];
inline bool cmp1(node x,node y) {return min(x.x-x.y,x.x-x.z)>min(y.x-y.y,y.x-y.z);}
inline bool cmp2(node x,node y) {return min(x.y-x.x,x.y-x.z)>min(y.y-y.x,y.y-y.z);}
inline bool cmp3(node x,node y) {return min(x.z-x.x,x.z-x.y)>min(y.z-y.x,y.z-y.y);}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);ta=0;tb=0;tc=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);int mx=max(x,max(y,z));
			if(x==mx) Ta[++ta]=(node){x,y,z},ans+=x;
			else if(y==mx) Tb[++tb]=(node){x,y,z},ans+=y;
			else if(z==mx) Tc[++tc]=(node){x,y,z},ans+=z;
		}
		if(ta<=n/2&&tb<=n/2&&tc<=n/2) {printf("%d\n",ans);continue;}
		sort(Ta+1,Ta+ta+1,cmp1);sort(Tb+1,Tb+tb+1,cmp2);sort(Tc+1,Tc+tc+1,cmp3);
		if(ta>n/2)
		{
			for(int i=ta;i>=n/2+1;i--)
			  if(Ta[i].x-Ta[i].y<Ta[i].x-Ta[i].z) ans-=Ta[i].x,ans+=Ta[i].y;
				else ans-=Ta[i].x,ans+=Ta[i].z;
		}
		if(tb>n/2)
		{
			for(int i=tb;i>=n/2+1;i--)
			  if(Tb[i].y-Tb[i].x<Tb[i].y-Tb[i].z) ans-=Tb[i].y,ans+=Tb[i].x;
				else ans-=Tb[i].y,ans+=Tb[i].z;
		}
		if(tc>n/2)
		{
			for(int i=tc;i>=n/2+1;i--)
			  if(Tc[i].z-Tc[i].x<Tc[i].z-Tc[i].y) ans-=Tc[i].z,ans+=Tc[i].x;
				else ans-=Tc[i].z,ans+=Tc[i].y;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//100
