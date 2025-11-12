#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,t;
struct node{
	long long x,y,z,sum,sum2;
	bool operator <(const node &cmp)const{
		return (sum-sum2)>(cmp.sum-cmp.sum2);
	}
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		}
		priority_queue<node> q1,q2,q3;
		long long sum=0,cnt1=0,cnt2=0,cnt3=0;
		for(long long i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(cnt1==n/2){
					node t=q1.top();
					q1.pop();
					if(max(t.y,t.z)+a[i].x>=t.sum){
						sum-=t.sum;
						sum+=max(t.y,t.z)+a[i].x;
						node t1=t;
						node t2;
						t2.x=a[i].x;
						t2.y=a[i].y;
						t2.z=a[i].z;
						t2.sum=a[i].x;
						if(t.y>=t.z){
							cnt2++;
							t1.sum=t.y;
							t1.sum2=max(t.x,t.z);
							if(a[i].y>=a[i].z) t2.sum2=a[i].y;
							else t2.sum2=a[i].z;
							q2.push(t1);
						}else{
							cnt3++;
							t1.sum=t.z;
							t1.sum2=max(t.x,t.y);
							if(a[i].y>=a[i].z)t2.sum2=a[i].y;
							else t2.sum2=a[i].z;
							q3.push(t1);
						}
						q1.push(t2);
					}else{
						sum+=max(a[i].y,a[i].z);
						node t1;
						t1.x=a[i].x;
						t1.y=a[i].y;
						t1.z=a[i].z;
						t1.sum=max(a[i].y,a[i].z);
						t1.sum2=a[i].x;
						if(a[i].y>=a[i].z)q2.push(t1),cnt2++;
						else q3.push(t1),cnt3++;
					}
				}else{
					sum+=a[i].x;
					cnt1++;
					node t1;
					t1.x=a[i].x;
					t1.y=a[i].y;
					t1.z=a[i].z;
					t1.sum=a[i].x;
					t1.sum2=max(a[i].y,a[i].z);
					q1.push(t1);
				}
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if(cnt2==n/2){
					node t=q2.top();
					q2.pop();
					if(max(t.x,t.z)+a[i].y>=t.sum){
						sum-=t.sum;
						sum+=max(t.x,t.z)+a[i].y;
						node t1=t;
						node t2;
						t2.x=a[i].x;
						t2.y=a[i].y;
						t2.z=a[i].z;
						t2.sum=a[i].y;
						if(t.x>=t.z){
							cnt1++;
							t1.sum=t.x;
							t1.sum2=max(t.y,t.z);
							if(a[i].x>=a[i].z){
								t2.sum2=a[i].x;
							}else{
								t2.sum2=a[i].z;
							}
							q1.push(t1);
						}else{
							cnt3++;
							t1.sum=t.z;
							t1.sum2=max(t.x,t.y);
							if(a[i].x>=a[i].z){
								t2.sum2=a[i].x;
							}else{
								t2.sum2=a[i].z;
							}
							q3.push(t1);
						}
						q2.push(t2);
					}else{
						sum+=max(a[i].x,a[i].z);
						node t1;
						t1.x=a[i].x;
						t1.y=a[i].y;
						t1.z=a[i].z;
						t1.sum=max(a[i].x,a[i].z);
						t1.sum2=a[i].y;
						if(a[i].x>=a[i].z)q1.push(t1),cnt1++;
						else q3.push(t1),cnt3++;
					}
				}else{
					sum+=a[i].y;
					cnt2++;
					node t1;
					t1.x=a[i].x;
					t1.y=a[i].y;
					t1.z=a[i].z;
					t1.sum=a[i].y;
					t1.sum2=max(a[i].x,a[i].z);
					q2.push(t1);
				}
			}else{
				if(cnt3==n/2){
					node t=q3.top();
					q3.pop();
					if(max(t.x,t.y)+a[i].z>=t.sum){
						sum-=t.sum;
						sum+=max(t.x,t.y)+a[i].z;
						node t1=t;
						node t2;
						t2.x=a[i].x;
						t2.y=a[i].y;
						t2.z=a[i].z;
						t2.sum=a[i].z;
						if(t.x>=t.y){
							cnt1++;
							t1.sum=t.x;
							t1.sum2=max(t.y,t.z);
							if(a[i].x>=a[i].y){
								t2.sum2=a[i].x;
							}else{
								t2.sum2=a[i].y;
							}
							q1.push(t1);
						}else{
							cnt2++;
							t1.sum=t.y;
							t1.sum2=max(t.x,t.z);
							if(a[i].x>=a[i].y){
								t2.sum2=a[i].x;
							}else{
								t2.sum2=a[i].y;
							}
							q2.push(t1);
						}
						q3.push(t2);
					}else{
						sum+=max(a[i].x,a[i].y);
						node t1;
						t1.x=a[i].x;
						t1.y=a[i].y;
						t1.z=a[i].z;
						t1.sum=max(a[i].x,a[i].y);
						t1.sum2=a[i].z;
						if(a[i].x>=a[i].y)q1.push(t1),cnt1++;
						else q2.push(t1),cnt2++;
					}
				}else{
					sum+=a[i].z;
					cnt3++;
					node t1;
					t1.x=a[i].x;
					t1.y=a[i].y;
					t1.z=a[i].z;
					t1.sum=a[i].z;
					t1.sum2=max(a[i].x,a[i].y);
					q3.push(t1);
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}