#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int n;
struct node{
	int x,y,z;
	int s;
	int xb;
}a[100010];
bool cmp(node s1,node s2){
	if(s1.xb==1&&s2.xb==1){
		return (s1.s-max(s1.y,s1.z))<(s2.s-max(s2.y,s2.z));
	}
	if(s1.xb==1&&s2.xb==2){
		return (s1.s-max(s1.y,s1.z))<(s2.s-max(s2.x,s2.z));
	}
	if(s1.xb==1&&s2.xb==3){
		return (s1.s-max(s1.y,s1.z))<(s2.s-max(s2.y,s2.x));
	}
	if(s1.xb==2&&s2.xb==1){
		return (s1.s-max(s1.x,s1.z))<(s2.s-max(s2.y,s2.z));
	}
	if(s1.xb==2&&s2.xb==2){
		return (s1.s-max(s1.x,s1.z))<(s2.s-max(s2.x,s2.z));
	}
	if(s1.xb==2&&s2.xb==3){
		return (s1.s-max(s1.x,s1.z))<(s2.s-max(s2.y,s2.x));
	}
	if(s1.xb==3&&s2.xb==1){
		return (s1.s-max(s1.y,s1.x))<(s2.s-max(s2.y,s2.z));
	}
	if(s1.xb==3&&s2.xb==2){
		return (s1.s-max(s1.y,s1.x))<(s2.s-max(s2.x,s2.z));
	}
	if(s1.xb==3&&s2.xb==3){
		return (s1.s-max(s1.y,s1.x))<(s2.s-max(s2.y,s2.x));
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		int b[10];
		b[1]=b[2]=b[3]=b[4]=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].s=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==a[i].s) b[1]++,a[i].xb=1;
			else if(a[i].y==a[i].s) b[2]++,a[i].xb=2;
			else if(a[i].z==a[i].s) b[3]++,a[i].xb=3;
			sum+=a[i].s;
		}
		if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2){
			cout<<sum<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(b[a[i].xb]>n/2){
				b[a[i].xb]--;
				int s1=a[i].s;
				if(a[i].xb==1){
					sum=sum-a[i].s+max(a[i].y,a[i].z);
				}
				if(a[i].xb==2){
					sum=sum-a[i].s+max(a[i].x,a[i].z);
				}
				if(a[i].xb==3){
					sum=sum-a[i].s+max(a[i].x,a[i].y);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
