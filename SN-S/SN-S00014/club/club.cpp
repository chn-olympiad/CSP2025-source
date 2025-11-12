#include<bits/stdc++.h>
using namespace std;
int a[100005][3],l[100005];
int bfs(int b1,int b2,int b3,int ans,int n){
	if(b1+b2+b3==n+1){
		return ans;
	}
	int b11=-1e9,b12=-1e9,b13=-1e9;
	if(b1<(n/2)) b11=bfs(b1+1,b2,b3,ans+a[b1+b2+b3+1][0],n);
	if(b2<(n/2)) b12=bfs(b1,b2+1,b3,ans+a[b1+b2+b3+1][1],n);
	if(b3<(n/2)) b13=bfs(b1,b2,b3+1,ans+a[b1+b2+b3+1][2],n);
	return max(b11,max(b12,b13));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			l[i]=a[i][0];
		}
		if(n<200) cout<<bfs(0,0,0,0,n)<<"\n";
		else{
			int ans=0;
			sort(l+1,l+n+1);
			for(int i=n;i>n/2;i++){
				ans+=l[i];
			}
			cout<<ans<<"\n";
		}
		for(int i=1;i<=n;i++){
			a[i][0]=a[i][1]=a[i][2]=0;
		}
	}
} 
