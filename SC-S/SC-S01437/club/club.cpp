#include<iostream> 
#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
const int mx=1e5+10;
struct node{
	int v1,v2,v3,max;
}a[mx];
int vis[mx*3];
int t,n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			for(int i=1;i<=n;i++){
				cin>>a[i].v1>>a[i].v2>>a[i].v3;
				a[i].max=max(max(a[i].v1,a[i].v2),a[i].v3);
			} 
			for(int i=1;i<=n;i++){
				ans+=a[i].max;
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++) cin>>vis[i];
			sort(vis,vis+1+n);
			cout<<vis[n];
		} 
	}
	return 0;
} 