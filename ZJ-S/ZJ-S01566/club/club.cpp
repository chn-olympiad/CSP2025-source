#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n;
struct node{
	int x;
	int y;
	int z;
}a[N];
int t[N];
bool cmp(node x,node y){
	return x.x-y.x>x.y-y.y;
}
int dfs(int x,int t1,int t2){
	if(x>n)return 0;
	int t3=x-1-t1-t2;
	int tt1=a[x].x;
	int tt2=a[x].y;
	int tt3=a[x].z;
	int ans1=-1e18;
	int ans2=-1e18;
	int ans3=-1e18;
	//1
	if(t1+1<=n/2)ans1=dfs(x+1,t1+1,t2)+tt1;
	//2
	if(t2+1<=n/2)ans2=dfs(x+1,t1,t2+1)+tt2;
	//3
	if(t3+1<=n/2)ans3=dfs(x+1,t1,t2)+tt3;
	
	return max(ans1,max(ans2,ans3));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		bool f=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				f=1;
			}
		}
		if(f==0){
			for(int i=1;i<=n;i++){
				t[i]=a[i].x;
			}
			sort(t+1,t+1+n);
			int ans=0;
			for(int i=n;i>=n/2;i--){
				ans+=t[i];
			}
			cout<<ans<<"\n";
		}
		if(n<=10)cout<<dfs(1,0,0)<<"\n";
		else{
			int ans=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
				t[i]=a[i].x-a[i].z;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].y;
				t[i]=a[i].y-a[i].z;
			}
			sort(t+1,t+1+n);
			for(int i=1;i<=n/2;i++){
				if(t[i]>=0)break;
				else{
					ans-=t[i];
				}
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}