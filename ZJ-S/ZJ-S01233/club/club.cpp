#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][5],sum;
void dfs(int step,ll u1,ll u2,ll u3,int v1,int v2,int v3){
	if(step==n){
		sum=max(sum,u1+u2+u3);
		return;
	}
	if(v1+1<=n/2)dfs(step+1,u1+a[step+1][1],u2,u3,v1+1,v2,v3);
	if(v2+1<=n/2)dfs(step+1,u1,u2+a[step+1][2],u3,v1,v2+1,v3);
	if(v3+1<=n/2)dfs(step+1,u1,u2,u3+a[step+1][3],v1,v2,v3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		bool flag=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)flag=1;
		}
		if(!flag){
			priority_queue<int>pq;
			int cnt=0,ans=0;
			for(int i=1;i<=n;i++)pq.push(a[i][1]);
			while(!pq.empty()&&cnt<=n/2){
				ans+=pq.top();
				pq.pop();
				cnt++;
			} 
			cout<<ans<<'\n';
		}
		else{
			sum=LLONG_MIN;
			dfs(0,0,0,0,0,0,0);
			cout<<sum<<'\n';
		}
	}
	return 0;
}
