#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z;
};
bool cmp(node a,node b){
	if(a.x==b.x){
		if(b.y==a.y) return a.z>b.z;
		return a.y>b.y;
	}
	return a.x>b.x;
}
bool awa(node a,node b){
	if(a.y==b.y){
		if(b.x==a.x) return a.z>b.z;
		return a.x>b.x;
	}
	return a.y>b.y;
}
bool owo(node a,node b){
	if(a.z==b.z){
		if(b.x==a.x) return a.y>b.y;
		return a.x>b.x;
	}
	return a.z>b.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	node a[100005];
	long long dpa[100005],dpb[100005],dpc[100005],ansa=0,ansb=0,ansc=0;
	cin>>t;
	while(--t){
		long long res=0;
		int ans=0;
		int cnt=0;
		memset(dpa,0,sizeof dpa);
		memset(dpb,0,sizeof dpb);
		memset(dpc,0,sizeof dpc);
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0) ans++;
			if(a[i].z==0) cnt++;
		}
		if(cnt==n&&ans==n){
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++){
				res+=a[i].x;
			}
			cout<<res<<endl;
			continue;
		}
		continue;
		ansa=n/2;
		ansb=n/2;
		ansc=n/2;
		sort(a+1,a+n+1,cmp);
		for(long long i=1;i<=n;i++){
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x&&ansa>0) {
				dpa[i]=max(dpa[i],dpa[i-1]+a[i].x);
				ansa--;
			}
			else{
				if(max(a[i].y,a[i].z)==a[i].y&&ansb>0) {
					dpa[i]=max(dpa[i],dpa[i-1]+a[i].y);
					ansb--;
				}
				else if(max(a[i].y,a[i].z)==a[i].z&&ansc>0) {
					dpa[i]=max(dpa[i],dpa[i-1]+a[i].z); 
					ansc--;	
				}
			}
		}
		ansa=n/2;
		ansb=n/2;
		ansc=n/2;
		sort(a+1,a+n+1,awa);
		for(long long i=1;i<=n;i++){
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y&&ansb>0) {
				dpb[i]=max(dpb[i],dpb[i-1]+a[i].y); 
				ansb--;	
			}
			else{
				if(max(a[i].x,a[i].z)==a[i].x&&ansa>0) {
					dpb[i]=max(dpb[i],dpb[i-1]+a[i].x);
					ansa--;
				}
				else if(max(a[i].x,a[i].z)==a[i].z&&ansc>0) {
					dpb[i]=max(dpb[i],dpb[i-1]+a[i].z); 
					ansc--;
				}
			}
		}
		ansa=n/2;
		ansb=n/2;
		ansc=n/2;
		sort(a+1,a+n+1,owo);
		for(long long i=1;i<=n;i++){
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].z&&ansc>0) {
				dpc[i]=max(dpc[i],dpc[i-1]+a[i].z); 
				ansc--;
			}
			else{
				if(max(a[i].x,a[i].y)==a[i].x&&ansa>0){
					dpc[i]=max(dpc[i],dpc[i-1]+a[i].x);
					ansa--;
				}
				else if(max(a[i].x,a[i].y)==a[i].y&&ansb>0){
					dpc[i]=max(dpc[i],dpc[i-1]+a[i].y); 
					ansb--;
				}
			}
		}
		cout<<max(dpc[n],max(dpa[n],dpb[n]))<<endl;
	}
	return 0;
} 
