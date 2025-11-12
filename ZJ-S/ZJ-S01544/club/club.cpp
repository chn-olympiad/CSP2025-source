#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c,d;
};
bool cmp1(Node a,Node b){
	return ((a.a-a.b)>(b.a-b.b));
}
bool cmp2(Node a,Node b){
	return ((a.a-a.c)>(b.a-b.c));
}
bool cmp3(Node a,Node b){
	return ((a.b-a.c)>(b.b-b.c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<Node> a(n);
		bool empa=1,empb=1,empc=1;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b or a[i].a>a[i].c){
				empa=0;
			}
			if(a[i].b>a[i].a or a[i].b>a[i].c){
				empb=0;
			}
			if(a[i].c>a[i].a or a[i].c>a[i].a){
				empc=0;
			}
		}
		if(empc==1){
			sort(a.begin(),a.end(),cmp1);
			int ans=0;
			for(int i=0;i<n;i++){
				ans+=(i<(int)(n/2))?a[i].a:a[i].b;
			}
			cout<<ans<<endl;
		}else if(empb==1){
			sort(a.begin(),a.end(),cmp2);
			int ans=0;
			for(int i=0;i<n;i++){
				ans+=(i<(int)(n/2))?a[i].a:a[i].c;
			}
			cout<<ans<<endl;
		}else if(empa==1){
			sort(a.begin(),a.end(),cmp3);
			int ans=0;
			for(int i=0;i<n;i++){
				ans+=(i<(int)(n/2))?a[i].b:a[i].c;
			}
			cout<<ans<<endl;
		}else{
			vector<vector<vector<int> > > dp(2,vector<vector<int> >((int)(n/2)+1,vector<int>((int)(n/2)+1,0)));
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,(int)(n/2));j++){
					for(int k=0;k<=min(i-j,(int)(n/2));k++){
						dp[i%2][j][k]=0;
						if(i-j-k<0 or i-j-k>=(int)(n/2)) continue;
						dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j][k]+a[i-1].c);
						if(j>0) dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j-1][k]+a[i-1].a);
						if(k>0) dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j][k-1]+a[i-1].b);
						if(i==n){
							ans=max(ans,dp[i%2][j][k]);
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
