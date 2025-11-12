#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int T,n,k[5];
struct node{
	int x,idx,y,idy;
}a[N];
inline bool cmp(node aa,node bb){
	return aa.x-aa.y>bb.x-bb.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		k[1]=k[2]=k[3]=0;
		int x,y,z;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				a[i].x=x;
				a[i].idx=1;
				if(y>=z){
					a[i].y=y;
					a[i].idy=2;
				}
				else{
					a[i].y=z;
					a[i].idy=3;
				}
			}
			if(y>=z&&y>=x){
				a[i].x=y;
				a[i].idx=2;
				if(x>=z){
					a[i].y=x;
					a[i].idy=1;
				}
				else{
					a[i].y=z;
					a[i].idy=3;
				}
			}
			if(z>=y&&z>=x){
				a[i].x=z;
				a[i].idx=3;
				if(y>=x){
					a[i].y=y;
					a[i].idy=2;
				}
				else{
					a[i].y=x;
					a[i].idy=1;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(k[a[i].idx]<n/2){
				ans+=a[i].x;
				k[a[i].idx]++;
			}
			else{
				ans+=a[i].y;
				k[a[i].idy]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
