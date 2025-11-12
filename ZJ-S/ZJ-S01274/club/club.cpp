#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int t,n,ans,cnt_x,cnt_y,cnt_z,visx,visy,visz,ans_x,jx,jy;
struct Node{
	int x,y,z;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
bool cmp_x(Node p,Node q){return p.x>q.x;}
bool cmp_y(Node p,Node q){return p.y>q.y;}
bool cmp_z(Node p,Node q){return p.z>q.z;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		memset(a,0,sizeof a);
		ans=0,cnt_x=0,cnt_y=0,cnt_z=0,visx=0,visy=0,visz=0,ans_x=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i].x=a[i+n].x=read();
			a[i].y=a[i+n].y=read();
			a[i].z=a[i+n].z=read();
			if(a[i].y!=0)jx=1;
			if(a[i].z!=0)jy=1;
		}
		if(!jx&&!jy){
			sort(a+1,a+1+n,cmp_x);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			printf("%d\n",ans);
			ans=0;
			continue;
		}else if(!jy){
			for(int k=1;k<=n;k++){
				for(int i=k+1,cnt=1;cnt<=n;cnt++,i++){
					if(visx){
						ans+=a[i].y;
					}else{
						if(a[i].x>=a[i].y){
							ans+=a[i].x;
							cnt_x++;
							if(cnt_x>=n/2)visx=1;
						}else{
							ans+=a[i].y;
							cnt_y++;
							if(cnt_y>=n/2)visy=1;
						}
					}
				}
				ans_x=max(ans_x,ans);
				ans=0;
				cnt_x=0,cnt_y=0,visx=0,visy=0;
			}
			ans=0;
			sort(a+1,a+1+n,cmp_x);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++)ans+=a[i].y;
			ans_x=max(ans_x,ans);
			ans=0;
			sort(a+1,a+1+n,cmp_y);
			for(int i=1;i<=n/2;i++)ans+=a[i].y;
			for(int i=n/2+1;i<=n;i++)ans+=a[i].x;
			printf("%d\n",ans_x);
			continue;
		}
		for(int k=1;k<=n;k++){
			for(int i=1+k,cnt=1;cnt<=n;cnt++,i++){
				if(visx){
					if(a[i].y>=a[i].z){
						cnt_y++;
						ans+=a[i].y;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visy){
					if(a[i].x>=a[i].z){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visz){
					if(a[i].x>=a[i].y){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_y++;
						ans+=a[i].y;
					}
				}else{
					if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
						ans+=a[i].x;
						cnt_x++;
						if(cnt_x>=n/2)visx=1;
					}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
						ans+=a[i].y;
						cnt_y++;
						if(cnt_y>=n/2)visy=1;
					}else{
						ans+=a[i].z;
						cnt_z++;
						if(cnt_z>=n/2)visz=1;
					}
				}
			}
			ans_x=max(ans_x,ans);
			ans=0;
			cnt_x=0,cnt_y=0,cnt_z=0;
			visx=0,visy=0,visz=0;
		}
		ans=0;
		cnt_x=0,cnt_y=0,cnt_z=0;
		visx=0,visy=0,visz=0;
		sort(a+1,a+1+n,cmp_x);
		for(int i=1;i<=n;i++)a[i+n]=a[i];
		for(int k=1;k<=n;k++){
			for(int i=1+k,cnt=1;cnt<=n;cnt++,i++){
				if(visx){
					if(a[i].y>=a[i].z){
						cnt_y++;
						ans+=a[i].y;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visy){
					if(a[i].x>=a[i].z){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visz){
					if(a[i].x>=a[i].y){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_y++;
						ans+=a[i].y;
					}
				}else{
					if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
						ans+=a[i].x;
						cnt_x++;
						if(cnt_x>=n/2)visx=1;
					}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
						ans+=a[i].y;
						cnt_y++;
						if(cnt_y>=n/2)visy=1;
					}else{
						ans+=a[i].z;
						cnt_z++;
						if(cnt_z>=n/2)visz=1;
					}
				}
			}
			ans_x=max(ans_x,ans);
			ans=0;
			cnt_x=0,cnt_y=0,cnt_z=0;
			visx=0,visy=0,visz=0;
		}
		sort(a+1,a+1+n,cmp_y);
		for(int i=1;i<=n;i++)a[i+n]=a[i];
		ans=0;
		cnt_x=0,cnt_y=0,cnt_z=0;
		visx=0,visy=0,visz=0;
		for(int k=1;k<=n;k++){
			for(int i=1+k,cnt=1;cnt<=n;cnt++,i++){
				if(visx){
					if(a[i].y>=a[i].z){
						cnt_y++;
						ans+=a[i].y;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visy){
					if(a[i].x>=a[i].z){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visz){
					if(a[i].x>=a[i].y){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_y++;
						ans+=a[i].y;
					}
				}else{
					if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
						ans+=a[i].x;
						cnt_x++;
						if(cnt_x>=n/2)visx=1;
					}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
						ans+=a[i].y;
						cnt_y++;
						if(cnt_y>=n/2)visy=1;
					}else{
						ans+=a[i].z;
						cnt_z++;
						if(cnt_z>=n/2)visz=1;
					}
				}
			}
			ans_x=max(ans_x,ans);
			ans=0;
			cnt_x=0,cnt_y=0,cnt_z=0;
			visx=0,visy=0,visz=0;
		}
		ans=0;
		cnt_x=0,cnt_y=0,cnt_z=0;
		visx=0,visy=0,visz=0;
		sort(a+1,a+1+n,cmp_z);
		for(int i=1;i<=n;i++)a[i+n]=a[i];
		for(int k=1;k<=n;k++){
			for(int i=1+k,cnt=1;cnt<=n;cnt++,i++){
				if(visx){
					if(a[i].y>=a[i].z){
						cnt_y++;
						ans+=a[i].y;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visy){
					if(a[i].x>=a[i].z){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_z++;
						ans+=a[i].z;
					}
				}else if(visz){
					if(a[i].x>=a[i].y){
						cnt_x++;
						ans+=a[i].x;
					}else{
						cnt_y++;
						ans+=a[i].y;
					}
				}else{
					if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
						ans+=a[i].x;
						cnt_x++;
						if(cnt_x>=n/2)visx=1;
					}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
						ans+=a[i].y;
						cnt_y++;
						if(cnt_y>=n/2)visy=1;
					}else{
						ans+=a[i].z;
						cnt_z++;
						if(cnt_z>=n/2)visz=1;
					}
				}
			}
			ans_x=max(ans_x,ans);
			ans=0;
			cnt_x=0,cnt_y=0,cnt_z=0;
			visx=0,visy=0,visz=0;
		}
		printf("%d\n",ans_x);
	}
	return 0;
}