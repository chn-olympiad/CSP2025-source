#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][5],tmp=0,b[100005];
long long ans=0;
void dfs(int step,int ca,int cb,int cc,long long sum){
	if(step>=n){
		ans=max(ans,sum);
		return;
	}
	if(ca<tmp)dfs(step+1,ca+1,cb,cc,sum+a[step][0]);
	if(cb<tmp)dfs(step+1,ca,cb+1,cc,sum+a[step][1]);
	if(cc<tmp)dfs(step+1,ca,cb,cc+1,sum+a[step][2]);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n>=30){
			bool flag=false;
			for(int i=0;i<100000;i++)b[i]=0;
			for(int i=0;i<n;i++){
				int x,y,z;
				cin>>x>>y>>z;
				if(y||z)flag=true;
				b[i]=max(x,max(y,z));
			}
//			cout<<flag<<'\n';
			sort(b,b+n,greater<int>());
			long long sum=0;
			for(int i=0;i<(flag?n:(n>>1));i++){
				sum+=b[i];
			}
			cout<<sum<<'\n';
			continue;
		}
		tmp=(n>>1);
		for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
