#include<bits/stdc++.h>
using namespace std;
const int N=1e5+16;
int T,n,l1,l2,l3;
long long ans;
struct data{
	int r1,r2,r3;
}a[N];
struct node{
	int val,leave;
}c1[N],c2[N],c3[N];
bool cmp(node i,node j){
	if(i.leave!=j.leave)return i.leave>j.leave;
	else return i.val>j.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].r1,&a[i].r2,&a[i].r3);
			if(a[i].r1>a[i].r2&&a[i].r1>a[i].r3){
				l1++;
				c1[l1].val=a[i].r1;
				c1[l1].leave=min(a[i].r1-a[i].r2,a[i].r1-a[i].r3);
			}else if(a[i].r2>a[i].r1&&a[i].r2>a[i].r3){
				l2++;
				c2[l2].val=a[i].r2;
				c2[l2].leave=min(a[i].r2-a[i].r3,a[i].r2-a[i].r1);
			}else if(a[i].r3>a[i].r2&&a[i].r3>a[i].r1){
				l3++;
				c3[l3].val=a[i].r3;
				c3[l3].leave=min(a[i].r3-a[i].r2,a[i].r3-a[i].r1);
			}else{
				if(a[i].r1==a[i].r2||a[i].r1==a[i].r3)ans+=a[i].r1;
				else ans+=a[i].r2;
			}
		}
		sort(c1+1,c1+l1+1,cmp);
		sort(c2+1,c2+l2+1,cmp);
		sort(c3+1,c3+l3+1,cmp);
		int tk=n/2;
		if(l1>tk){
			for(int i=tk+1;i<=l1;i++){
				ans-=c1[i].leave;
			}
		}else if(l2>tk){
			for(int i=tk+1;i<=l2;i++){
				ans-=c2[i].leave;				
			}
		}else if(l3>tk){
			for(int i=tk+1;i<=l3;i++){
				ans-=c3[i].leave;				
			}
		}
		for(int i=1;i<=l1;i++){
			ans+=c1[i].val;
			c1[i].leave=0;
			c1[i].val=0;			
		}
		for(int i=1;i<=l2;i++){
			ans+=c2[i].val;
			c2[i].leave=0;
			c2[i].val=0;			
		}
		for(int i=1;i<=l3;i++){
			ans+=c3[i].val;
			c3[i].leave=0;
			c3[i].val=0;			
		}
		printf("%lld\n",ans);	
		n=0;
		l1=0;
		l2=0;
		l3=0;
		ans=0;	
	}
	return 0;
} 