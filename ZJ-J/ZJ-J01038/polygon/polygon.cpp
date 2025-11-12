#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],ans;
bool vis[5010];
void f(int x,int m,int sm,int mx,int la){
	if(x==m+1){
		if(sm>mx*2) (ans+=1)%=mod;
		return ;
	}
	for(int i=la;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		f(x+1,m,sm+a[i],max(mx,a[i]),i+1);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) f(1,i,0,0,1);
	cout<<ans;
	return 0;
}
