#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	ll x,y,z,s,f;
}a[100010];
ll t,n,d1,d2,d3,ans,flag,cnt1,cnt2,p=1,q=1;
ll del1[100010],del2[100010];
bool cmp1(st u,st v){
		return u.z-u.x>v.z-v.x;
}
bool cmp2(st u,st v){
		return u.z-u.y>v.z-v.y;
}
bool cmp(st u,st v){
	return abs(u.x-u.y)>abs(v.x-v.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n;
		d1=d2=d3=n/2;
		flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].s=abs(a[i].x-a[i].y)+abs(a[i].x-a[i].z)+abs(a[i].z-a[i].y);
			if(a[i].z!=0){
				flag=1;
			}
		}

			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(d1<=0){
					ans+=a[i].y;
					a[i].f=2;
					continue;
				}
				if(d2<=0){
					ans+=a[i].x;
					a[i].f=1;
					continue;
				}
				if(d1>0&&a[i].x>a[i].y){
					ans+=a[i].x;
					a[i].f=1;
					d1--;
				}
				if(d2>0&&a[i].x<a[i].y){
					ans+=a[i].y;
					a[i].f=2;
					d2--;
				}
			}
			if(flag){
				sort(a+1,a+1+n,cmp1);
				for(int i=1;i<=n;i++){
					if(a[i].f==1&&a[i].z-a[i].x>0){
						del1[++cnt1]=a[i].z-a[i].x;
					}
				}
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=n;i++){
					if(a[i].f==2&&a[i].z-a[i].y>0){
						del2[++cnt2]=a[i].z-a[i].y;
					}
				}
				while(d3>0&&p<=cnt1&&q<=cnt2){
					if(del1[p]>del2[q]){
						ans+=del1[p];
						p++;
						d3--;
					}else{
						ans+=del2[q]; 
						q++;
						d3--;
					}
				}
			}
			cout<<ans<<endl;
		}
	return 0;
}
