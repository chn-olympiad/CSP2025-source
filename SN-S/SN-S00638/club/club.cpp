#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z,t;
}a[100010];
bool cmp(node c,node b){
	return c.x>b.x;
}
bool cmp1(node c,node b){
	return c.y>b.y;
}
bool cmp2(node c,node b){
	return c.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ans=0,maxx;
		bool flag=0;
		for(int j=1;j<=n;j++) {
			cin>>a[j].x>>a[j].y>>a[j].z;
			a[j].t=i;
		}
		for(int j=1;j<=n;j++){
			if(a[j].x==0&&a[j].z==0) flag=1;
			else {
				flag=0;
				break;
			}
		}
		if(flag==1) {
			sort(a+1,a+n+1,cmp1);
			for(int j=1;j<=n/2;j++) ans+=a[j].y;
			cout<<ans<<endl; 
		}
		else{
//			int b=n/2,maxx1=0,maxx2=0,maxx3=0,maxx=0,cnt=0;
//			for(int j=2;j<=n;j++) maxx1=max(a[j-1].x,a[j].x);
//			for(int j=2;j<=n;j++) maxx2=max(a[j-1].y,a[j].y);
//			for(int j=2;j<=n;j++) maxx3=max(a[j-1].z,a[j].z);
//			maxx=max(maxx1,maxx2);
//			maxx=max(maxx,maxx3);
//			if(maxx==maxx1){
//				sort(a+1,a+n+1,cmp);
//				for(int j=2;j<=n/2;j++){
//					if(a[j].x!=a[j-1].x) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].x; 
//				sort(a+1,a+n+1,cmp1);
//				for(int j=2;j<=n/2;j++){
//					if(a[j].y!=a[j-1].y) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].y; 
//				sort(a+1,a+n+1,cmp2);
//				for(int j=2;j<=n/2;j++){
//					if(a[j].z!=a[j-1].z) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].z; 
//				
//			}else if(maxx==maxx2){
//				sort(a+1,a+n+1,cmp1);
//				for(int j=2;j<=n;j++){
//					if(a[j].y!=a[j-1].y) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].y; 
//				sort(a+1,a+n+1,cmp);
//				for(int j=2;j<=n/2;j++){
//					if(a[j].x!=a[j-1].x) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].x; 
//				sort(a+1,a+n+1,cmp2);
//				for(int j=2;j<=n;j++){
//					if(a[j].z!=a[j-1].z) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].z; 
//			}else if(maxx==maxx3){
//				sort(a+1,a+n+1,cmp2);
//				for(int j=2;j<=n;j++){
//					if(a[j].z!=a[j-1].z) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].z; 
//				sort(a+1,a+n+1,cmp);
//				for(int j=2;j<=n/2;j++){
//					if(a[j].x!=a[j-1].x) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].x; 
//				sort(a+1,a+n+1,cmp1);
//				for(int j=2;j<=n;j++){
//					if(a[j].y!=a[j-1].y) break;
//					else cnt++;
//				}
//				if(cnt<=n/2) ans+=cnt*a[1].y; 
//			}
			for(int j=1;j<=n;j++){
				int maxx=0;
				maxx=max(a[j].x,a[j].y);
				maxx=max(maxx,a[j].z);
				ans+=maxx;
			}
			cout<<ans;
		}
	}
	return 0;
}
