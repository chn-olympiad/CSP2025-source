#include<bits/stdc++.h>
using namespace std;
int T;
struct node{
	int d1,d2,d3;
	int m1,m2,m3,n1,n2,n3;
}a[200010];
bool cmp(node x,node y){
	if(x.m1==y.m1){
		if(x.m2==y.m2)return x.m3>y.m3;
		return x.m2>y.m2;
	}
	return x.m1>y.m1;
}
int n;int d[4];long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		d[1]=d[2]=d[3]=0;ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].d1,&a[i].d2,&a[i].d3);
			if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
				a[i].m1=a[i].d1;a[i].n1=1;
				if(a[i].d2>=a[i].d3){
					a[i].m2=a[i].d2;a[i].n2=2;
					a[i].m3=a[i].d3;a[i].n3=3;
				}
				else{
					a[i].m2=a[i].d3;a[i].n2=3;
					a[i].m3=a[i].d2;a[i].n3=2;
				}
			}
			else if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
				a[i].m1=a[i].d2;a[i].n1=2;
				if(a[i].d1>=a[i].d3){
					a[i].m2=a[i].d1;a[i].n2=1;
					a[i].m3=a[i].d3;a[i].n3=3;
				}
				else{
					a[i].m2=a[i].d3;a[i].n2=3;
					a[i].m3=a[i].d1;a[i].n3=1;
				}
			}
			else{
				a[i].m1=a[i].d3;a[i].n1=3;
				if(a[i].d1>=a[i].d2){
					a[i].m2=a[i].d1;a[i].n2=1;
					a[i].m3=a[i].d2;a[i].n3=2;
				}
				else{
					a[i].m2=a[i].d2;a[i].n2=2;
					a[i].m3=a[i].d1;a[i].n3=1;
				}
			}		
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(d[a[i].n1]<(n/2)){
				d[a[i].n1]++;ans+=a[i].m1;
			}
			else if(d[a[i].n2]<(n/2)){
				d[a[i].n2]++;ans+=a[i].m2;
			}
			else{
				d[a[i].n3]++;ans+=a[i].m3;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
