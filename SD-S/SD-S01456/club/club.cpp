#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stu{
	int x;
	int y;
	int z;
}a[N];
int ans;
int f[5];
bool check(int n){
	for(int i=1;i<=n;i++){
		if(a[i].y!=0||a[i].z!=0) return false;
		return true;
	}
}
int cnt;
void dfs(int c,int n){
	if(c==n+1){
		ans=max(ans,cnt);
		//cout<<"ttt"<<ans<<endl;
		return ;
	}
	
	if(f[1]<n/2){
		f[1]++;
		cnt+=a[c].x;
		dfs(c+1,n);
		cnt-=a[c].x;
		f[1]--;
	}
	if(f[2]<n/2){
		f[2]++;
		cnt+=a[c].y;
		dfs(c+1,n);
		cnt-=a[c].y;
		f[2]--;
	}
	
	if(f[3]<n/2){
		f[3]++;
		cnt+=a[c].z;
		dfs(c+1,n);
		cnt-=a[c].z;
		f[3]--;
	}
}
bool cmp(stu x,stu y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(check(n)){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<'\n';
			continue;
		}
		else{
			dfs(1,n);
			cout<<ans<<'\n';
		}
		cnt=0;
	}
	return 0;
}
