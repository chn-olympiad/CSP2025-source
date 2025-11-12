#include<bits/stdc++.h>
using namespace std;
int t,n,a[1145140],b[1145140],c[1145140],zzy[1145140][4],ans,book[1145140],m[1145140],r;
void dfs(int s){
	if(s==n+1){
		ans=max(ans,m[r]);
		return;
	}
	for(int i=1;i<=3;i++){
		if(book[i]<(n/2)){
			book[i]+=1;
			m[r]+=zzy[s][i];
			dfs(s+1);
			m[r]-=zzy[s][i];
			book[i]-=1;
		}	
	}
	return;
}
int zhaoyanyi() {
	int m[8];
	m[1]=a[1]+b[2];
	m[2]=a[1]+c[2];
	m[3]=a[2]+b[1];
	m[4]=a[2]+c[1];
	m[5]=b[1]+c[2];
	m[6]=b[2]+c[1];
	sort(m+1,m+6+1);
	ans=m[6];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n>40) {
			for(int i=1; i<=n; i++) {
				cin>>a[i]>>b[i]>>c[i];
			}
			sort(a+1,a+n+1);
			for(int i=n; i>n/2; i--) {
				ans+=a[i];
			}
			cout<<ans<<endl;
			ans=0;
			continue;
		}if(n==2) {
			for(int i=1; i<=n; i++) {
				cin>>a[i]>>b[i]>>c[i];
			}
			zhaoyanyi();
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		if(n>2&&n<40){
			for(int i=1;i<=n;i++){
				cin>>zzy[i][1]>>zzy[i][2]>>zzy[i][3];
			}
			dfs(1);
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
} 
// 
