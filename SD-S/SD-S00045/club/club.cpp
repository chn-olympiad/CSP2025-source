#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
int t,n,a[100005][5],num[5],delt[100005];
long long ans=0;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		num[1]=num[2]=num[3]=0;
		ans=0;
		scanf("%d",&n);
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=1ll*a[i][1]; 
				num[1]++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=1ll*a[i][2];
				num[2]++;
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				ans+=1ll*a[i][3];
				num[3]++;
			}
		}
		if(num[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					q.push(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
				}
			}
			int tot=0;
			while(!q.empty()&&tot<num[1]-n/2){
				ans-=q.top();
				q.pop();
				tot++;
			}
		}
		else if(num[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					q.push(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
				}
			}
			int tot=0;
			while(!q.empty()&&tot<num[2]-n/2){
				ans-=q.top();
				q.pop();
				tot++;
			}
		}
		else if(num[3]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
					q.push(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
				}
			}
			int tot=0;
			while(!q.empty()&&tot<num[3]-n/2){
				ans-=q.top();
				q.pop();
				tot++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
