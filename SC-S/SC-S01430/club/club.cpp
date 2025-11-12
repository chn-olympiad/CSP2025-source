#include<bits/stdc++.h>
using namespace std;
int n,a[100005][3],t,u,v,w,ans,tt,cnt;
priority_queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--){
		cin>>n;
		u=v=w=ans=cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) u++;
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][0]) v++;
			if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]) w++;
		}
		if(u<=(n>>1)&&v<=(n>>1)&&w<=(n>>1)){
			for(int i=1;i<=n;i++) {
				ans+=max(a[i][0],max(a[i][1],a[i][2]));
			}
			cout<<ans<<'\n';
			continue;
		}
		if(u>(n>>1)) t=0;
		if(v>(n>>1)) t=1;
		if(w>(n>>1)) t=2;
		int ne=(t+1)%3,af=(t+2)%3;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(a[i][t]>max(a[i][ne],a[i][af])) {
				if(cnt<(n>>1)){
					cnt++;
					q.push(max(a[i][ne],a[i][af])-a[i][t]);
					ans+=a[i][t];
				}
				else{
					if(max(a[i][ne],a[i][af])<q.top()+a[i][t]){
						ans+=q.top()+a[i][t];
						q.pop();
						q.push(max(a[i][ne],a[i][af])-a[i][t]);
					}
					else ans+=max(a[i][ne],a[i][af]);
				}
			}
			else ans+=max(a[i][ne],a[i][af]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}


