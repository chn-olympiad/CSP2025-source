#include <iostream>
#include <cstring>
using namespace std;
struct club{
	int like1;
	int like2;
	int like3;
}a[100005];
int vis[100005];
long long n,ans;
void dfs(int a1,int a2,int a3,long long sum){
	int s=a1+a2+a3;
	if(s==n){
		ans=max(ans,sum);
		return;
	}
	else{
		if(a1<n/2){
			dfs(a1+1,a2,a3,sum+a[s+1].like1);
		}
		if(a2<n/2){
			dfs(a1,a2+1,a3,sum+a[s+1].like2);
		}
		if(a3<n/2){
			dfs(a1,a2,a3+1,sum+a[s+1].like3);
		}
	}
}
void fun(){
	cin>>n;
	ans=0;
	memset(vis,0,sizeof(vis)); 
	for(int i=1;i<=n;i++){
		cin>>a[i].like1>>a[i].like2>>a[i].like3;
	}
	dfs(0,0,0,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		fun();
	}
	return 0;

}
