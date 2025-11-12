#include<bits/stdc++.h>
using namespace std;
//struct node{
//	int val,pos,id;
//}a[500005];
//bool cmp(node aa,node bb){
//	if(aa.val==bb.val)return aa.pos<bb.pos;
//	return aa.val>bb.val;
//}
struct node{
	int g,m,x,y,z,mi,mid;
}a[500005];
bool cmp(node aa,node bb){
	return aa.g>bb.g;
}
int cnt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		int n,u,v,w;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&u,&v,&w);
//			ans+=u;
			int x=max(u,max(v,w)),y=min(u,min(v,w)),z;
			if(x==u){
				a[i].x=1;
				if(y==w){
					z=v;
					a[i].z=2;
					a[i].y=3;
				}
				else{
					a[i].z=3;
					a[i].y=2;
					z=w;
				}
			}
			if(x==w){
				a[i].x=3;
				if(y==u){
					z=v;
					a[i].z=2;
					a[i].y=1;					
				}
				else{
					a[i].z=1;
					a[i].y=2;					
					z=u;
				}
			}
			if(x==v){
				a[i].x=2;
				if(y==w){
					a[i].z=1;
					a[i].y=3;					
					z=u;
				}
				else{
					a[i].z=3;
					a[i].y=1;					
					z=w;
				}
			}
			a[i].g=x-z;
			a[i].m=x;
			a[i].mid=z;
			a[i].mi=y;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if((cnt[a[i].x]+1)*2<=n){
				cnt[a[i].x]++;
				ans+=a[i].m;
			}
			else if((cnt[a[i].z]+1)*2<=n){
				cnt[a[i].z]++;
				ans+=a[i].mid;
			}
			else if((cnt[a[i].y]+1)*2<=n){
				cnt[a[i].y]++;
				ans+=a[i].mi;
			}
//			printf("%lld\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
