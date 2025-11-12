#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;

int T,n,ans;
struct node{
	int a,b,c;
}a[N];

bool cmp(node x,node y){
	return x.a>y.a;
} 

void dfs(int x,int y,int z,int step,int cnt){
	if(step>n){
		ans=max(ans,cnt);
		return;
	}
	if(x<(n/2)) dfs(x+1,y,z,step+1,cnt+a[step].a);
	if(y<(n/2)) dfs(x,y+1,z,step+1,cnt+a[step].b);
	if(z<(n/2)) dfs(x,y,z+1,step+1,cnt+a[step].c);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		int tmp=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==0&&a[i].c==0){
				++tmp;
			}
		}
		if(tmp==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;		
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,0,0,1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
