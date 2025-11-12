#include<bits/stdc++.h>
using namespace std;
int t,n;
struct stu{
	int x,y,z,ma;
}a[100005];
priority_queue<int,vector<int>,greater<int> > q[4];
bool cmp(stu a,stu b){
	return a.ma>b.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i].ma=max(max(a[i].x,a[i].y),a[i].z);
		}
		sort(a+1,a+1+n,cmp);
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].ma==a[i].x){
				if(cnt1<n/2){
					cnt1++;
					ans+=a[i].ma;
					q[1].push(a[i].x-max(a[i].y,a[i].z));
				}
				else{
					int p=a[i].x-max(a[i].y,a[i].z);
					if(p>q[1].top()){
						ans=ans+a[i].x-q[1].top();
						q[1].pop();
						q[1].push(a[i].x-max(a[i].y,a[i].z));
					}
					else{
						if(a[i].y>a[i].z){
							cnt2++;
						}
						else{
							cnt3++;
						}
						ans+=max(a[i].y,a[i].z);
					}
				}
			}
			else if(a[i].ma==a[i].y){
				if(cnt2<n/2){
					cnt2++;
					ans+=a[i].ma;
					q[2].push(a[i].y-max(a[i].x,a[i].z));
				}
				else{
					int p=a[i].y-max(a[i].x,a[i].z);
					if(p>q[2].top()){
						ans=ans+a[i].y-q[2].top();
						q[2].pop();
						q[2].push(a[i].y-max(a[i].x,a[i].z));
					}
					else{
						if(a[i].x>a[i].z){
							cnt1++;
						}
						else{
							cnt3++;
						}
						ans+=max(a[i].x,a[i].z);
					}
				}
			}
			else if(a[i].ma==a[i].z){
				if(cnt3<n/2){
					cnt3++;
					ans+=a[i].ma;
					q[3].push(a[i].z-max(a[i].y,a[i].x));
				}
				else{
					int p=a[i].z-max(a[i].y,a[i].x);
					if(p>q[3].top()){
						ans=ans+a[i].z-q[3].top();
						q[3].pop();
						q[3].push(a[i].z-max(a[i].y,a[i].x));
					}
					else{
						if(a[i].y>a[i].x){
							cnt2++;
						}
						else{
							cnt1++;
						}
						ans+=max(a[i].y,a[i].x);
					}
				}
			}
		}
		while(!q[1].empty()){
			q[1].pop();
		} 
		while(!q[2].empty()){
			q[2].pop();
		}
		while(!q[3].empty()){
			q[3].pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}

