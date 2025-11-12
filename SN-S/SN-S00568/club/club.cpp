#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int a,b,c,ans=0,f[N][4];
		memset(f,0,sizeof(f));
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
//			f[i][1]=a;
//			f[i][2]=b;
//			f[i][3]=c;
			ans+=max(a,max(b,c));
		}
//		for(int j=1;j<=3;j++){
//			for(int i=1;i<=n;i++){
//				for(int k=i+1;k<=n;k++){
//					maxx=max(maxx,f[i][j]+f[k][j]);					
//				}
//				
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<f[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		for(int i=1;i<=n;i++){
//			cin>>a[i].f>>a[i].c>>a[i].t;
//		}
//		sort(a+1,a+n+1,cmp);
//		int k=n/2;
//		for(int i=1;i<=k;i++){
//			if(vis[i]==0){
//				ans+=a[i].f;
//				vis[i]=1;				
//			}
//		}
//		for(int i=1;i<=k;i++){
//			if(vis[i]==0){
//				ans+=a[i].c;
//				vis[i]=1;				
//			}
//		}
//		for(int i=1;i<=k;i++){
//			if(vis[i]==0){
//				ans+=a[i].t;
//				vis[i]=1;				
//			}
//		}
//		cout<<ans;
		cout<<ans;
	}
	return 0;
}
