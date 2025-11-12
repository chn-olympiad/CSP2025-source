#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int T,n;
struct wcy{
	int a[4];
	int fi,se,th;
	void read(){
		cin>>a[1]>>a[2]>>a[3];
	}
}t[N];
int num[4],ans;
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(num[1]+1<=n/2){
		num[1]++;
		dfs(x+1,sum+t[x].a[1]);
		num[1]--;
	}
	if(num[2]+1<=n/2){
		num[2]++;
		dfs(x+1,sum+t[x].a[2]);
		num[2]--;
	}
	if(num[3]+1<=n/2){
		num[3]++;
		dfs(x+1,sum+t[x].a[3]);
		num[3]--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			t[i].read();
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
