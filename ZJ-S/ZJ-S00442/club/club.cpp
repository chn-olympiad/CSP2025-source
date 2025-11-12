#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,ans,sum[4],x,y,z,i;
struct no{
	ll x,y,z,id;
}a[100100];
bool cmp(no xx,no yy){
	if (xx.x-xx.y==yy.x-yy.y) return xx.y-xx.z>yy.y-yy.z;
	return xx.x-xx.y>yy.x-yy.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);ans=0;sum[1]=sum[2]=sum[3]=0;
		for (i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			if (x>=y&&x>=z){
				if (y>=z){a[i].x=x;a[i].y=y;a[i].z=z;a[i].id=123;}
				else{a[i].x=x;a[i].y=z;a[i].z=y;a[i].id=132;}
			}
			else if(y>=x&&y>=z){
				if (x>=z){a[i].x=y;a[i].y=x;a[i].z=z;a[i].id=213;}
				else{a[i].x=y;a[i].y=z;a[i].z=x;a[i].id=231;}
			}
			else{
				if (x>=y){a[i].x=z;a[i].y=x;a[i].z=y;a[i].id=312;}
				else{a[i].x=z;a[i].y=y;a[i].z=x;a[i].id=321;}
			}
		}
		sort(a+1,a+1+n,cmp);
		for (i=1;i<=n;i++){
			if (sum[a[i].id/100]==n/2){
				ans+=a[i].y;
				sum[(a[i].id/10)%10]++;
			}
			else{
				sum[a[i].id/100]++;
				ans+=a[i].x;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/