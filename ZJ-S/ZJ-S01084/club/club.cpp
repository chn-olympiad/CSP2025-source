#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z,flag;
}a[100005];
bool cmp(node a,node b){
	return a.flag<b.flag;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,x1=0,x2=0,x3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].flag=max(max(a[i].x,a[i].y),a[i].z)*2-a[i].x-a[i].y-a[i].z+min(min(a[i].x,a[i].y),a[i].z);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				ans+=a[i].x;
				x1++;
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				ans+=a[i].y;
				x2++;
			}else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
				ans+=a[i].z;
				x3++;
			}
		}
		if(x1>(n/2)){
			for(int i=1;i<=n;i++){
				if(x1==(n/2)){
					break;
				}
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
					ans-=a[i].flag;
					x1--;
				}
			}
		}else if(x2>(n/2)){
			for(int i=1;i<=n;i++){
				if(x2==(n/2)){
					break;
				}
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
					ans-=a[i].flag;
					x2--;
				}
			}
		}else if(x3>(n/2)){
			for(int i=1;i<=n;i++){
				if(x3==(n/2)){
					break;
				}
				if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
					ans-=a[i].flag;
					x3--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
