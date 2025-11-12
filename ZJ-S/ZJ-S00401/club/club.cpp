#include <bits/stdc++.h>
using namespace std;
struct node{
	int b[3],x,y,p;
}a[100010];
int t,n,x,y,z,h[3],ans;
bool cmp(node a,node b){
	return a.p<b.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		memset(h,0,sizeof(h));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].b[0],&a[i].b[1],&a[i].b[2]);
			if(a[i].b[0]>=a[i].b[1] and a[i].b[0]>=a[i].b[2]){
				a[i].x=0;a[i].p=a[i].b[0]-max(a[i].b[1],a[i].b[2]);
				ans+=a[i].b[0];
			}else if(a[i].b[1]>=a[i].b[2] and a[i].b[1]>=a[i].b[0]){
				a[i].x=1;a[i].p=a[i].b[1]-max(a[i].b[0],a[i].b[2]);
				ans+=a[i].b[1];
			}else if(a[i].b[2]>=a[i].b[1] and a[i].b[2]>=a[i].b[0]){
				a[i].x=2;a[i].p=a[i].b[2]-max(a[i].b[1],a[i].b[0]);
				ans+=a[i].b[2];
			}
			h[a[i].x]++;
		}
		sort(a,a+n,cmp);
		int tmp=0;
		for(int i=0;i<3;i++){
			while(h[i]>n/2){
				if(a[tmp].x==i){
					ans-=a[tmp].p;
					h[i]--;
				}
				tmp++;
			}		
		}
		printf("%d\n",ans);
	}
	return 0;
}

