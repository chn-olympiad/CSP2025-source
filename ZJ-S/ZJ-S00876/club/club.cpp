#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=1e5+10;
int n;
int ans;
int res;

struct Node{
	int x,y,z;
}a[N];

void dfs(int k,int x,int y,int z,int sum){
//	cout<<k<<" "<<x<<" "<<y<<" "<<z<<" "<<sum<<"\n";
	if(ans<sum) ans=sum;
	if(k>n) return ;
	
	if(x<n/2) dfs(k+1,x+1,y,z,sum+a[k].x);
	if(y<n/2) dfs(k+1,x,y+1,z,sum+a[k].y);
	if(z<n/2) dfs(k+1,x,y,z+1,sum+a[k].z);
}

namespace sub2{
	bool cmp(Node A,Node B){
		return A.x>B.x;
	}
	
	void solve(){
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				f=0;
			}
		}
		
		if(f){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			return ;
		}
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n>200){
			sub2::solve();
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
