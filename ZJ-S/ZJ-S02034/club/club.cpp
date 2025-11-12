#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n,a[N],b[N],c[N],ans;
void dfs(int x,int s1,int s2,int s3,int tot){
	if(s1>n/2||s2>n/2||s3>n/2) return;
	if(tot>n){
		ans=max(ans,x);
		return;
	}
	dfs(x+a[tot],s1+1,s2,s3,tot+1);
	dfs(x+b[tot],s1,s2+1,s3,tot+1);
	dfs(x+c[tot],s1,s2,s3+1,tot+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	int x,y,z;
	while(t--){
		x=0,y=0,z=0;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0) x++;
			if(c[i]==0) y++;
		}
		if(x==y&&x==n){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--){
				z+=a[i];
			}
			cout<<z<<"\n";
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}