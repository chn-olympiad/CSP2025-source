#include<bits/stdc++.h>
using namespace std;
int p[5];
struct f{
	int x,y,z,sum,mx,mn,mid,t,w;
}a[200001];
bool cmp(f e,f u){
	return e.sum>u.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>=a[i].z)a[i].mx=1;
			if(a[i].y>a[i].x&&a[i].y>=a[i].z)a[i].mx=2;
			if(a[i].z>a[i].y&&a[i].z>=a[i].x)a[i].mx=3;
			if(a[i].x==a[i].y&&a[i].x==a[i].z)a[i].w=1;
			if(a[i].x==a[i].y&&a[i].x!=a[i].z)a[i].t=3;
			if(a[i].z==a[i].y&&a[i].z!=a[i].x)a[i].t=1;
			if(a[i].x==a[i].z&&a[i].x!=a[i].y)a[i].t=2;
			if(max(a[i].x,a[i].z)>a[i].y&&min(a[i].x,a[i].z)<a[i].y)a[i].mid=2;
			if(max(a[i].y,a[i].z)>a[i].x&&min(a[i].y,a[i].z)<a[i].x)a[i].mid=1;
			if(max(a[i].x,a[i].y)>a[i].z&&min(a[i].x,a[i].y)<a[i].z)a[i].mid=3;
			if(a[i].x<a[i].y&&a[i].x<a[i].z)a[i].mn=1;
			if(a[i].y<a[i].z&&a[i].y<a[i].x)a[i].mn=2;
			if(a[i].z<a[i].x&&a[i].z<a[i].y)a[i].mn=3;
			if(a[i].w==1)continue;
			int l=0,r=0;
			if(a[i].mx==1)l=a[i].x;
			if(a[i].mx==2)l=a[i].y;
			if(a[i].mx==3)l=a[i].z;
			if(a[i].mid==1)r=a[i].x;
			if(a[i].mid==2)r=a[i].y;
			if(a[i].mid==3)r=a[i].z;
			if(a[i].t==1)a[i].sum=max(a[i].x,a[i].y)-min(a[i].x,a[i].y);
			if(a[i].t==2)a[i].sum=max(a[i].x,a[i].y)-min(a[i].x,a[i].y);
			if(a[i].t==3)a[i].sum=max(a[i].z,a[i].y)-min(a[i].z,a[i].y);
			a[i].sum=l-r;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].w==1)ans+=a[i].x;
			else if(a[i].t==1){
				if(a[i].y>a[i].x)ans+=a[i].y;
				else{
					if(p[1]<n/2)ans+=a[i].x,p[1]++;
					else ans+=a[i].y;
				}
			}
			else if(a[i].t==2){
				if(a[i].x>a[i].y)ans+=a[i].x;
				else{
					if(p[2]<n/2)ans+=a[i].y,p[2]++;
					else ans+=a[i].x;
				}
			}
			else if(a[i].t==3){
				if(a[i].y>a[i].z)ans+=a[i].y;
				else{
					if(p[3]<n/2)ans+=a[i].z,p[3]++;
					else ans+=a[i].y;
				}
			}
			else if(a[i].mx==1){
				if(p[1]<n/2)ans+=a[i].x,p[1]++;
				else{
					if(a[i].mid==2)ans+=a[i].y;
					if(a[i].mid==3)ans+=a[i].z;
				}
			}
			else if(a[i].mx==2){
				if(p[2]<n/2)ans+=a[i].y,p[2]++;
				else{
					if(a[i].mid==1)ans+=a[i].x;
					if(a[i].mid==3)ans+=a[i].z;
				}
			}
			else if(a[i].mx==3){
				if(p[3]<n/2)ans+=a[i].z,p[3]++;
				else{
					if(a[i].mid==2)ans+=a[i].y;
					if(a[i].mid==1)ans+=a[i].x;
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
