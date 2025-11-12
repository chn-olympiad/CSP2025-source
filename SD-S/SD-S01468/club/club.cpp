#include<bits/stdc++.h>//,vector<int>,geather<int> 
using namespace std;
const int N=1e5+10;
priority_queue<int>q;
int x[N],y[N],z[N];
int cnt[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		}
		int sumx=0,sumy=0,sumz=0;
		for(int i=1;i<=n;i++){
			if(max(max(x[i],y[i]),z[i])==x[i]){
				sumx++;
				cnt[i]=1;
			}
			else if(max(max(x[i],y[i]),z[i])==y[i]){
				sumy++;
				cnt[i]=2;
			}
			else if(max(max(x[i],y[i]),z[i])==z[i]){
				sumz++;
				cnt[i]=3;
			}
		}
		long long ans=0;
		if(sumx>n/2){
			for(int i=1;i<=n;i++){
				if(cnt[i]==1){
					q.push(max(y[i]-x[i],z[i]-x[i]));
				}
			}
			for(int i=sumx;i>n/2;i--){
				ans+=q.top();
				q.pop();
			}
		}
		else if(sumy>n/2){
			for(int i=1;i<=n;i++){
				if(cnt[i]==2){
					q.push(max(x[i]-y[i],z[i]-y[i]));
				}
			}
			for(int i=sumy;i>n/2;i--){
				ans+=q.top();
				q.pop();
			}
		}
		else if(sumz>n/2){
			for(int i=1;i<=n;i++){
				if(cnt[i]==3){
					q.push(max(x[i]-z[i],y[i]-z[i]));
				}
			}
			for(int i=sumz;i>n/2;i--){
				ans+=q.top();
				q.pop();
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[i]==1)
			ans+=x[i];
			if(cnt[i]==2)
			ans+=y[i];
			if(cnt[i]==3)
			ans+=z[i];
		}
		printf("%lld\n",ans);
		while(q.size())
		q.pop();
	}
	return 0;
}
//注意到最多只有一个组会爆炸。
//而又注意到 将人数最多的组的多余人数转到其他组不会导致其他组炸掉
//n是偶数果然是有用的 
//done 
