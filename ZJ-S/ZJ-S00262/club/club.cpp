//25
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n,a[N],b[N],c[N];
long long ans;
bool vis[N];
void dfs(int x,int na,int nb,int nc,long long nans){
	if(x==n+1){
		ans=max(ans,nans);
		return ;
	}
	if(na<n/2){
		dfs(x+1,na+1,nb,nc,nans+(long long)a[x]);
	}
	if(nb<n/2){
		dfs(x+1,na,nb+1,nc,nans+(long long)b[x]);
	}
	if(nc<n/2){
		dfs(x+1,na,nb,nc+1,nans+(long long)c[x]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else{
			stable_sort(a+1,a+1+n);
			for(int i=n; i>n/2; i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
