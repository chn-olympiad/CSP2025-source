#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=1e6+112;
ll t;
ll n,a[N][5],ans,q;
//int改成ll  多测清空 
ll vv[N][3];
ll p1[N],cn1,p2[N],cn2,p3[N],cn3;
ll cnt;
ll M0,M1,fal[N];
struct node{
	ll val;
	ll ID;
}v0[N],v1[N];

bool cmp(node x,node y)
{
	if(x.val!=y.val) return x.val<y.val;
	else return x.ID<y.ID;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%lld",&t);
	while(t--)
	{
		ans=0,q=0,cnt=0;
		M0=0,M1=0;
		for(ll i=0;i<=n+5;i++)
		{
			a[i][1]=a[i][2]=a[i][3]=0;
			vv[i][0]=vv[i][1]=0;
			fal[i]=0;
			v0[i].val=v1[i].val=0;
			v0[i].ID=v1[i].ID=0;
		}
		for(ll i=0;i<=cn1;i++) p1[i]=0;
		for(ll i=0;i<=cn2;i++) p2[i]=0;
		for(ll i=0;i<=cn3;i++) p3[i]=0;
		cn1=cn2=cn3=0;
		
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				vv[i][0]=a[i][1]-a[i][2];
				vv[i][1]=a[i][1]-a[i][3];
				p1[++cn1]=i;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				vv[i][0]=a[i][2]-a[i][1];
				vv[i][1]=a[i][2]-a[i][3];
				p2[++cn2]=i;
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) {
				vv[i][0]=a[i][3]-a[i][1];
				vv[i][1]=a[i][3]-a[i][2];
				p3[++cn3]=i;
			}
		}
		
		if(cn1>n/2) {
			cnt=cn1;
			q=cn1-n/2;
			M0=n/2-cn2;
			M1=n/2-cn3;
			
			for(ll i=1;i<=cn1;i++) {
				v0[i].val=vv[p1[i]][0];
				v1[i].val=vv[p1[i]][1];
				v0[i].ID=v1[i].ID=i;
			}
		}
		else if(cn2>n/2) {
			cnt=cn2;
			q=cn2-n/2;
			M0=n/2-cn1;
			M1=n/2-cn3;
			
			for(ll i=1;i<=cn2;i++) {
				v0[i].val=vv[p2[i]][0];
				v1[i].val=vv[p2[i]][1];
				v0[i].ID=v1[i].ID=i;
			}
		}
		else if(cn3>n/3) {
			cnt=cn3;
			q=cn3-n/2;
			M0=n/2-cn1;
			M1=n/2-cn2;
			
			for(ll i=1;i<=cn3;i++) {
				v0[i].val=vv[p3[i]][0];
				v1[i].val=vv[p3[i]][1];
				v0[i].ID=v1[i].ID=i;
			}
		}
		else {
			printf("%lld\n",ans);
			continue; 
		}
		
		sort(v0+1,v0+1+cnt,cmp);
		sort(v1+1,v1+1+cnt,cmp);
		
		ll per=0,sumv=0,i0=1,i1=1,fin0=0,fin1=0;
		while(per!=q)
		{
			if(fal[v0[i0].ID]) 
			{
				i0++;
				continue;
			}
			if(fal[v1[i1].ID])
			{
				i1++;
				continue;
			}
			
			if(fin0==M0||i0>cnt)
			{
				sumv+=v1[i1].val;
				fal[v1[i1].ID]=1;
				per++;
				fin1++;
				i1++;
			}
			else if(fin1==M1||i1>cnt)
			{
				sumv+=v0[i0].val;
				fal[v0[i0].ID]=1;
				per++;
				fin0++;
				i0++;
			}
			else {
				if(v0[i0].val<v1[i1].val)
				{
					sumv+=v0[i0].val;
					fal[v0[i0].ID]=1;
					per++;
					fin0++;
					i0++;
				}
				else {
					sumv+=v1[i1].val;
					fal[v1[i1].ID]=1;
					per++;
					fin1++;
					i1++;
				}
			}
		}
		
		printf("%lld\n",ans-sumv);
		
	}
	
	
	return 0;
}
/*
1
30
4 2 1
3 2 4
5 3 4
3 5 1
9 7 8
11 3 12
9 8 0
7 0 4
2 4 3
5 13 0
9 6 0
0 0 9
0 9 0
0 0 0
2 6 5
11 9 13
4 6 5
8 3 9
10 2 9
0 11 3
9 3 8
0 1 2
4 5 7
9 1 4
7 8 2
11223 432 543
998 11099 322
123 657 888
1024 1412 9999
99908 55567 77854
*/