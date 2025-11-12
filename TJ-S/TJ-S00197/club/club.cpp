#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005];
long long ans=0;
int cnt1,cnt2,cnt3;
priority_queue<int>q;
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);  
	cin>>t;
	for(int k=1;k<=t;k++){
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a1[i]>=max(a2[i],a3[i])){
				cnt1++;
				ans+=a1[i];
			}
			else if(a2[i]>=max(a1[i],a3[i])){
				cnt2++;
				ans+=a2[i];
			}
			else if(a3[i]>=max(a1[i],a3[i])){
				cnt3++;
				ans+=a3[i];
			}
		}
		if(max(cnt1,max(cnt2,cnt3))>n/2){
			if(cnt1>=max(cnt2,cnt3)){
				for(int i=1;i<=n;i++){
					if(a1[i]>=max(a2[i],a3[i])){
						q.push(max(-a1[i]+a2[i],-a1[i]+a3[i]));
					}
				}
				for(int i=1;i<=cnt1-n/2;i++){
					ans+=q.top();
					q.pop();
					//cout<<ans<<endl;
				}
			}
			else if(cnt2>=max(cnt1,cnt3)){
				for(int i=1;i<=n;i++){
					if(a2[i]>=max(a1[i],a3[i])){
						q.push(max(-a2[i]+a1[i],-a2[i]+a3[i]));
					}
				}
				for(int i=1;i<=cnt2-n/2;i++){
					ans+=q.top();
					q.pop();
					//cout<<ans<<endl;
				}
			}
			else if(cnt3>=max(cnt1,cnt2)){
				for(int i=1;i<=n;i++){
					if(a3[i]>=max(a1[i],a2[i])){
						q.push(max(-a3[i]+a2[i],-a3[i]+a1[i]));
					}
				}
				for(int i=1;i<=cnt3-n/2;i++){
					ans+=q.top();
					q.pop();
					//cout<<ans<<endl;
				}
			}
		}
		while(!q.empty())q.pop(); 
		cout<<ans<<endl;
	}
	return 0; 
} 
