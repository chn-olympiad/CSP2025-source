#include <iostream>
using namespace std;
const int N=1e5+10;
int n,a[N][4],s[4],ans,t;
void dfs(int x,int k,int s[]){
	ans=max(ans,k);
	for(int i=1; i<=3; i++){
		if(s[i]+1<=n/2 && x<=n){
			s[i]+=1,dfs(x+1,k+a[x][i],s),s[i]-=1;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=max(a[1][1],max(a[1][2],a[1][3]));
		dfs(1,0,s);
		cout<<ans<<endl;
	}
	return 0;
}
