#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1e6+5,inf=1e18;
int n,a[N][3];
int cnt[3];
int ans[N];
priority_queue<int>q;
void sl(){
	while(!q.empty())q.pop();
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i][0]=read();
		a[i][1]=read();
		a[i][2]=read();
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=mx;
		if(a[i][0]==mx){
			cnt[0]++;
		}
		else if(a[i][1]==mx){
			cnt[1]++;
		}
		else if(a[i][2]==mx){
			cnt[2]++;
		}
	}
	int mx=max(cnt[0],max(cnt[1],cnt[2]));
	if(mx>n/2){
		if(cnt[0]==mx){
			for(int i=1;i<=n;i++){
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])q.push(max(a[i][1]-a[i][0],a[i][2]-a[i][0]));
			}
			for(int i=1;i<=mx-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		else if(cnt[1]==mx){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])q.push(max(a[i][2]-a[i][1],a[i][0]-a[i][1]));
			}
			for(int i=1;i<=mx-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])q.push(max(a[i][1]-a[i][2],a[i][0]-a[i][2]));
			}
			for(int i=1;i<=mx-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt=1;
	cin>>tt;
	while(tt--)sl();
	return 0;
} 
