#include<bits/stdc++.h>
using namespace std;
long long ans;


int n, t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	scanf("%d",&t);
	while (t--){
		ans=0;
		int a1[100010],a2[100010],a3[100010];
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			scanf("%d",&a1[i]);
			scanf("%d",&a2[i]);
			scanf("%d",&a3[i]);
		}
		sort(a1+1,a1+n+1);
		sort(a2+1,a2+n+1);
		sort(a3+1,a3+n+1);
		int q1=0,q2=0,q3=0,c=n,c2=n,c3=n;
		while(c!=0&&q1+q2+q3<n){
		
			if(q1<n/2&&a1[c]>a2[c]){
				if(q1<n/2&&a1[c]>a3[c]){
					q1++;
					ans+=a1[c];
				}else if(q3<n/2&&a1[c]<a3[c]){
					q3++;
					ans+=a3[c];
				}else{
					int ac=c;
					while(ac!=0&&a1[ac]==a3[ac]){
						ac--;
					}
					if(q1<n/2&&a1[ac+1]>=a3[ac+1]){
						q1++;
						ans+=a1[c];
					}else if(q3<n/2&&q3<n/2){
						q3++;
						ans+=a3[c];
					}
					
				}
			}else if(q2<n/2&&a2[c]<a1[c]){
				if(q1<n/2&&a2[c]>a3[c]){
					q2++;
					ans+=a2[c];
				}else if(q3<n/2&&a2[c]<a3[c]){
					q3++;
					ans+=a3[c];
				}else{
					int ac=c;
					while(ac!=0&&a2[ac]==a3[ac]){
						ac--;
					}
					if(q2<n/2&&a2[ac+1]>=a3[ac+1]){
						q2++;
						ans+=a2[c];
					}else if(q1<n/2){
						q3++;
						ans+=a3[c];
					}
				}
			}else{int w=0,e=0;
				if(q2<n/2&&a2[c]>a1[c]){
					q2++;
					ans+=a2[c];
				}else if(q1<n/2&&a2[c]<a1[c]){
					q1++;
					ans+=a1[c];
				}else{
					int ac=c;
					while(ac!=0&&a2[ac]==a1[ac]){
						ac--;
					}
					if(q2<n/2&&a2[ac+1]>=a1[ac+1]){
						w=2;
						e=a2[c];
					}else if(q1<n/2){
						w=1;
						e=a1[c];
					}
				}
				int ac1=c;
					while(e!=0&&w==2?a2[ac1]:a1[ac1]==a3[ac1]){
						ac1--;
					}
					if(w==2?q2<n/2:q1<n/2&& w==2?a2[ac1+1]:a1[ac1=1]>=a3[ac1+1]){
						w==2?q2++:q1++;
						ans+=w==2?a2[c]:a1[c];
					}else if(q3<n/2){
						q3++;
						ans+=a3[c];
					}
			}
			
			c--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
