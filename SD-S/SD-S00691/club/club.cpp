#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,tp;
}a[100010];
int b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		int c1=0,c2=0,c3=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)ans+=a[i].x,c1++,a[i].tp=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)ans+=a[i].y,c2++,a[i].tp=2;
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)ans+=a[i].z,c3++,a[i].tp=3;
		}
		int sz=0;
		if(c1>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].tp==1)b[++sz]=max(a[i].y-a[i].x,a[i].z-a[i].x);
			}
			sort(b+1,b+sz+1);
			for(int j=sz;j>n/2;j--)ans+=b[j];
		}else if(c2>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].tp==2)b[++sz]=max(a[i].x-a[i].y,a[i].z-a[i].y);
			}
			sort(b+1,b+sz+1);
			for(int j=sz;j>n/2;j--)ans+=b[j];
		}else if(c3>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].tp==3)b[++sz]=max(a[i].x-a[i].z,a[i].y-a[i].z);
			}
			sort(b+1,b+sz+1);
			for(int j=sz;j>n/2;j--)ans+=b[j];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
