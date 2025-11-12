#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int maxans;
struct node{
	int x,y,z;
	int max,mid,min;
}a[100008];
bool cmp1(node a,node b){
	if(a.max>b.max) return true;
	else if(a.max<b.max) return false;
	else{
		if(a.mid>b.mid) return true;
		else if(a.mid<b.mid) return false;
		else return a.min>b.min;
	}
}
bool cmp2(node a,node b){
	if(a.max>b.max) return true;
	else if(a.max<b.max) return false;
	else{
		if(a.mid>b.mid) return true;
		else if(a.mid<b.mid) return false;
		else return a.min<b.min;
	}
}
bool cmp3(node a,node b){
	if(a.max>b.max) return true;
	else if(a.max<b.max) return false;
	else{
		if(a.mid<b.mid) return true;
		else if(a.mid>b.mid) return false;
		else return a.min>b.min;
	}
}
bool cmp4(node a,node b){
	if(a.max<b.max) return true;
	else if(a.max>b.max) return false;
	else{
		if(a.mid>b.mid) return true;
		else if(a.mid<b.mid) return false;
		else return a.min>b.min;
	}
}
bool cmp5(node a,node b){
	if(a.max>b.max) return true;
	else if(a.max<b.max) return false;
	else{
		if(a.mid<b.mid) return true;
		else if(a.mid>b.mid) return false;
		else return a.min<b.min;
	}
}
bool cmp6(node a,node b){
	if(a.max<b.max) return true;
	else if(a.max>b.max) return false;
	else{
		if(a.mid>b.mid) return true;
		else if(a.mid<b.mid) return false;
		else return a.min<b.min;
	}
}
bool cmp7(node a,node b){
	if(a.max<b.max) return true;
	else if(a.max>b.max) return false;
	else{
		if(a.mid<b.mid) return true;
		else if(a.mid>b.mid) return false;
		else return a.min>b.min;
	}
}
bool cmp8(node a,node b){
	if(a.max<b.max) return true;
	else if(a.max>b.max) return false;
	else{
		if(a.mid<b.mid) return true;
		else if(a.mid>b.mid) return false;
		else return a.min<b.min;
	}
}
int main(){
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		maxans=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].max=max(a[i].x,max(a[i].y,a[i].z));
			a[i].min=min(a[i].x,min(a[i].y,a[i].z));
			if((a[i].max==a[i].x&&a[i].min==a[i].y)||(a[i].min==a[i].x&&a[i].max==a[i].y)){
				a[i].mid=a[i].z;
			}else if((a[i].max==a[i].x&&a[i].min==a[i].z)||(a[i].min==a[i].x&&a[i].max==a[i].z)){
				a[i].mid=a[i].y;
			}else if((a[i].max==a[i].y&&a[i].min==a[i].z)||(a[i].min==a[i].y&&a[i].max==a[i].z)){
				a[i].mid=a[i].x;
			}
		}
		sort(a+1,a+n+1,cmp1);
		int kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp2);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp3);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp4);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp5);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp6);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp7);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		sort(a+1,a+n+1,cmp8);
		kx=0,ky=0,kz=0,ans=0;
		for(int i=1;i<=n;++i){
			if(kx!=-1&&a[i].max==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].max==a[i].y){
				ans+=a[i].y;	
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].max==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].mid==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].mid==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].mid==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}else if(kx!=-1&&a[i].min==a[i].x){
				ans+=a[i].x;
				++kx;
				if(kx*2==n) kx=-1;
			}else if(ky!=-1&&a[i].min==a[i].y){
				ans+=a[i].y;
				++ky;
				if(ky*2==n) ky=-1;
			}else if(kz!=-1&&a[i].min==a[i].z){
				ans+=a[i].z;
				++kz;
				if(kz*2==n) kz=-1;
			}
		}
		maxans=max(maxans,ans);
		printf("%d\n",maxans);
	}
	return 0;
}
