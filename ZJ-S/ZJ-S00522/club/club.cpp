#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x,y,z;
	int mov;
	bool ay,by,cy;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		int maxnum=n/2;
		long long ans=0;
		int ax,bx,cx;
		ax=bx=cx=0;
		for(int i=1;i<=n;++i){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				ax++;
				a[i].ay=true;
				a[i].mov=(a[i].x-max(a[i].y,a[i].z));
				ans+=a[i].x;
			}else{
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
					bx++;
					a[i].by=true;
					a[i].mov=(a[i].y-max(a[i].x,a[i].z));
					ans+=a[i].y;
				}else{
					if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
						cx++;
						a[i].cy=true;
						a[i].mov=(a[i].z-max(a[i].x,a[i].y));
						ans+=a[i].z;
					}
				}
			}
		}
		if(ax>maxnum){
			int giveout=ax-maxnum;
			int ap[10005],pp=1;
			for(int i=1;i<=n;++i){
				if(a[i].ay){
					ap[pp]=a[i].mov;
					++pp;
				}
			}
			sort(ap+1,ap+pp);
			for(int i=1;i<=giveout;++i){
				ans-=ap[i];
			}
		}
		if(bx>maxnum){
			int giveout=bx-maxnum;
			int ap[10005],pp=1;
			for(int i=1;i<=n;++i){
				if(a[i].by){
					ap[pp]=a[i].mov;
					++pp;
				}
			}
			sort(ap+1,ap+pp);
			for(int i=1;i<=giveout;++i){
				ans-=ap[i];
			}
		}
		if(cx>maxnum){
			int giveout=cx-maxnum;
			int ap[10005],pp=1;
			for(int i=1;i<=n;++i){
				if(a[i].cy){
					ap[pp]=a[i].mov;
					++pp;
				}
			}
			sort(ap+1,ap+pp);
			for(int i=1;i<=giveout;++i){
				ans-=ap[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}