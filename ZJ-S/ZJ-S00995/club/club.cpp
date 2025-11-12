#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,ans;
struct Person{
	int x,y,z;
}a[100100];
priority_queue<int>q[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				ans+=a[i].x;
				q[1].push(max(a[i].y-a[i].x,a[i].z-a[i].x));
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				ans+=a[i].y;
				q[2].push(max(a[i].x-a[i].y,a[i].z-a[i].y));
			}else{
				ans+=a[i].z;
				q[3].push(max(a[i].x-a[i].z,a[i].y-a[i].z));
			}
		}
		int len1=q[1].size(),len2=q[2].size(),len3=q[3].size();
		while(len1>n/2){
			ans+=q[1].top();q[1].pop();
			--len1;
		}
		while(len2>n/2){
			ans+=q[2].top();q[2].pop();
			--len2;
		}
		while(len3>n/2){
			ans+=q[3].top();q[3].pop();
			--len3;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
