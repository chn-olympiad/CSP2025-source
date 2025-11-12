#include<bits/stdc++.h>
using namespace std;
int n,m,T,a[101010][3];
priority_queue<int>dui[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		long long ans=0;
		for(int i=0;i<3;i++)while(!dui[i].empty())dui[i].pop();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				dui[0].push(max(a[i][1],a[i][2])-a[i][0]);
				ans+=a[i][0];
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				dui[1].push(max(a[i][0],a[i][2])-a[i][1]);
				ans+=a[i][1];
			}else{
				dui[2].push(max(a[i][0],a[i][1])-a[i][2]);
				ans+=a[i][2];
			}
		}
		for(int i=0;i<3;i++){
			if((int)dui[i].size()>n/2){
				while(dui[i].size()>n/2){
					ans+=dui[i].top();
					dui[i].pop();
				}
			}
		}printf("%lld\n",ans);
	}
	return 0;
}
