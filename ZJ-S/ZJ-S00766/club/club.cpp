#include <bits/stdc++.h>
using namespace std;
long long n,T,i,cnt,ans,num,b[100010],c[100010],p[10];
struct node{
	long long x,y,z;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0;num=0;
		p[1]=p[2]=p[3]=0;
		for(i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				b[i]=1;p[1]++;
				ans+=a[i].x;
			} 
			if(a[i].y>a[i].x&&a[i].y>=a[i].z){
				b[i]=2;p[2]++;
				ans+=a[i].y;
			}
			if(a[i].z>a[i].x&&a[i].z>a[i].y){
				b[i]=3;p[3]++;
				ans+=a[i].z;
			}
		}
		if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		if(p[1]>n/2){
			cnt=p[1]-n/2;
			for(i=1;i<=n;i++)
				if(b[i]==1)
					c[++num]=min(a[i].x-a[i].y,a[i].x-a[i].z);
			stable_sort(c+1,c+1+num);
			for(i=1;i<=cnt;i++)
				ans-=c[i];
		}
		if(p[2]>n/2){
			cnt=p[2]-n/2;
			for(i=1;i<=n;i++)
				if(b[i]==2)
					c[++num]=min(a[i].y-a[i].x,a[i].y-a[i].z);
			stable_sort(c+1,c+1+num);
			for(i=1;i<=cnt;i++)
				ans-=c[i];
		}
		if(p[3]>n/2){
			cnt=p[3]-n/2;
			for(i=1;i<=n;i++)
				if(b[i]==3)
					c[++num]=min(a[i].z-a[i].x,a[i].z-a[i].y);
			stable_sort(c+1,c+1+num);
			for(i=1;i<=cnt;i++)
				ans-=c[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
