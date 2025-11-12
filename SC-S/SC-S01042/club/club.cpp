//club
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int T,n,c1,c2,c0,ans;
int a[N][5],b[N],d[N];
priority_queue<int> q;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		c0=c1=c2=ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=max({a[i][0],a[i][1],a[i][2]});
			ans+=mx;
			if(mx==a[i][0]){
				c0++;
				b[i]=0;
				d[i]=max(a[i][1]-mx,a[i][2]-mx);
			}else if(mx==a[i][1]){
				c1++;
				b[i]=1;
				d[i]=max(a[i][0]-mx,a[i][2]-mx);
			}else{
				c2++;
				b[i]=2;
				d[i]=max(a[i][1]-mx,a[i][0]-mx);
			}
		}
		while(!q.empty()) q.pop();
		if(c0>n/2){
			int ds=c0-n/2;
			for(int i=1;i<=n;++i){
				if(b[i]==0) q.push(d[i]);
			}
			while(ds--){
				ans+=q.top();
				q.pop();
			}
		}
		if(c1>n/2){
			int ds=c1-n/2;
			for(int i=1;i<=n;++i){
				if(b[i]==1) q.push(d[i]);
			}
			while(ds--){
				ans+=q.top();
				q.pop();
			}
		}
		if(c2>n/2){
			int ds=c2-n/2;
			for(int i=1;i<=n;++i){
				if(b[i]==2) q.push(d[i]);
			}
			while(ds--){
				ans+=q.top();
				q.pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}