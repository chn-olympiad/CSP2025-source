#include<bits/stdc++.h>
using namespace std;
struct infor{
	int q,w,e;
};
bool cmp1(infor a,infor b){
	if(a.q==b.q){
		if(a.w==b.w)
			return a.e>b.e;
		return a.w>b.w;
	}
	return a.q>b.q;
}
bool cmp2(infor a,infor b){
	if(a.q==b.q){
		if(a.e==b.e)
			return a.w>b.w;
		return a.e>b.e;
	}
	return a.q>b.q;
}
bool cmp3(infor a,infor b){
	if(a.w==b.w){
		if(a.q==b.q)
			return a.e>b.e;
		return a.q>b.q;
	}
	return a.w>b.w;
}
bool cmp4(infor a,infor b){
	if(a.w==b.w){
		if(a.e==b.e)
			return a.q>b.q;
		return a.e>b.e;
	}
	return a.w>b.w;
}
bool cmp5(infor a,infor b){
	if(a.e==b.e){
		if(a.q==b.q)
			return a.w>b.w;
		return a.q>b.q;
	}
	return a.e>b.e;
}
bool cmp6(infor a,infor b){
	if(a.e==b.e){
		if(a.w==b.w)
			return a.q>b.q;
		return a.w>b.w;
	}
	return a.e>b.e;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,ans=0,aa=0,bb=0,cc=0,z,x,c;cin>>n;infor a[100005];
		for(int i=1;i<=n;i++){
			cin>>a[i].q>>a[i].w>>a[i].e;
			z+=a[i].q;x+=a[i].w;c+=a[i].e;
		}
		if(z>=x&&x>=c)
			sort(a+1,a+n+1,cmp1);
		else if(z>=c&&c>=x)
			sort(a+1,a+n+1,cmp2);
		else if(x>=z&&z>=c)
			sort(a+1,a+n+1,cmp3);
		else if(x>=c&&c>=z)
			sort(a+1,a+n+1,cmp4);
		else if(c>=z&&z>=x)
			sort(a+1,a+n+1,cmp5);
		else if(c>=x&&x>=z)
			sort(a+1,a+n+1,cmp6);
		for(int i=1;i<=n;i++){
			int hh=max(a[i].q,max(a[i].w,a[i].e));
			if(hh==a[i].q){if(aa<n/2){ans+=a[i].q;aa++;}else if(a[i].w>a[i].e){ans+=a[i].w;bb++;}else{ans+=a[i].e;cc++;}}
			if(hh==a[i].q){if(bb<n/2){ans+=a[i].w;bb++;}else if(a[i].e>a[i].q){ans+=a[i].e;cc++;}else{ans+=a[i].q;aa++;}}
			if(hh==a[i].q){if(cc<n/2){ans+=a[i].e;cc++;}else if(a[i].q>a[i].w){ans+=a[i].q;aa++;}else{ans+=a[i].w;bb++;}}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
