#include<bits/stdc++.h>
using namespace std;
int a[100010][3];
struct C{
	int cha,idx;
}c[100010];
bool cmp(C aa,C bb){
	return aa.cha>bb.cha;
}
int g(int x,int y,int z){
	if(x>=y){
		if(x>=z)return 1;
		return 3;
	}else{
		if(y>=z)return 2;
		return 3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			c[i].cha=max(max(a[i][0],a[i][1]),a[i][2])-(a[i][0]+a[i][1]+a[i][2]-max(max(a[i][0],a[i][1]),a[i][2])-min(min(a[i][0],a[i][1]),a[i][2]));
			c[i].idx=i;
		}
		sort(c+1,c+1+n,cmp);
		int x=0,y=0,z=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int idx=c[i].idx;
			int now=g(a[idx][0],a[idx][1],a[idx][2]);
			if(now==1){
				if(x<n/2){
					ans+=a[idx][0];
					x++;
				}else{
					if(a[idx][1]>a[idx][2]){
						ans+=a[idx][1];
						y++;
					}else{
						ans+=a[idx][2];
						z++;
					}
				}
			}else if(now==2){
				if(y<n/2){
					ans+=a[idx][1];
					y++;
				}else{
					if(a[idx][0]>a[idx][2]){
						ans+=a[idx][0];
						x++;
					}else{
						ans+=a[idx][2];
						z++;
					}
				}
			}else{
				if(z<n/2){
					ans+=a[idx][2];
					z++;
				}else{
					if(a[idx][1]>a[idx][0]){
						ans+=a[idx][1];
						y++;
					}else{
						ans+=a[idx][0];
						x++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}